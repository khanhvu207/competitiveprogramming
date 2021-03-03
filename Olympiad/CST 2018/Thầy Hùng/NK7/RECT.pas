//	46/50
const fi = 'RECT.INP';
      fo = 'RECT.OUT';
label l1;
type point = record
           x,y: longint;
     end;
     line = record
          p1,p2: point;
     end;
     sty = record
         l: array[1..4] of line;
     end;
var f: text;
    n,dem,ans,i,j,k,z: longint;
    x1,y1,x2,y2,x3,y3,x4,y4: longint;
    a: array [1..2000] of sty;
    fre: array [1..2000] of boolean;
    c: array [1..2000,1..2000] of boolean;

function ccw(a,b,c: Point): integer;
  var dx1,dx2,dy1,dy2,d: real;
  begin
      dx1 := b.x-a.x; dy1 := b.y-a.y;
      dx2 := c.x-a.x; dy2 := c.y-a.y;
      d := dx1*dy2 - dy1*dx2;

      if d < 0 then exit(-1);
      if d > 0 then exit(1);
      if d = 0 then
        begin
            if (dx1*dx2 < 0) or (dy1*dy2 < 0) then exit(-1);
            if sqr(dx1)+sqr(dy1) >= sqr(dx2) + sqr(dy2) then exit(0) else exit(1);
        end;
  end;

function intersect(l1,l2: Line): boolean;
  var A,B,C,D: Point;
  begin
      A:= l1.p1; B:= l1.p2;
      C:= l2.p1; D:= l2.p2;
      if (ccw(A,B,C)*ccw(A,B,D) <= 0) and (ccw(C,D,A)*ccw(C,D,B) <= 0) then exit(true) else exit(false);
  end;

procedure dfs(u: longint);
  var v: longint;
  begin
      inc(dem);
      fre[u]:=false;
      for v:=1 to n do
        if fre[v] and c[u,v] then dfs(v);
  end;

BEGIN
    assign(f,fi); reset(f);
    read(f,n);
    fillchar(c,sizeof(c),false);
    for i:=1 to n do
      begin
          read(f,x1,y1,x2,y2,x3,y3,x4,y4);
          with a[i] do
            begin
                l[1].p1.x:=x1; l[1].p1.y:=y1; l[1].p2.x:=x2; l[1].p2.y:=y2;
                l[2].p1.x:=x2; l[2].p1.y:=y2; l[2].p2.x:=x3; l[2].p2.y:=y3;
                l[3].p1.x:=x3; l[3].p1.y:=y3; l[3].p2.x:=x4; l[3].p2.y:=y4;
                l[4].p1.x:=x4; l[4].p1.y:=y4; l[4].p2.x:=x1; l[4].p2.y:=y1;
            end;
      end;

    for i:=1 to n-1 do
      for j:=i+1 to n do
        begin
            for k:=1 to 4 do
              for z:=1 to 4 do
                  if intersect(a[i].l[k], a[j].l[z]) then
                    begin
                        c[i,j]:=true; c[j,i]:=true;
                        goto l1;
                    end;
            l1:
        end;

    ans:=0;
    fillchar(fre,sizeof(fre),true);
    for i:=1 to n do
      if fre[i] then
        begin
            dem:=0;
            dfs(i);
            if dem>ans then ans:=dem;
        end;

    assign(f,fo); rewrite(f); writeln(f,ans); close(f);
END.
