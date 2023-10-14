label l1;
const fi = 'hcn.inp';
      fo = 'hcn.out';
type point = record
           x,y: longint;
     end;
     line = record
          p1,p2: point;
     end;
     sty = record
         canh: array [1..4] of line;
     end;
var f: text;
    tg: array [1..1000] of sty;
    n,i,j,k,z,ans: longint;
    x1,y1,x2,y2,x3,y3,x4,y4: longint;
    fre: array [1..1000] of boolean;
    c: array [1..1000,1..1000] of boolean;

function ccw(A,B,C: point): integer;
  var dx1,dy1,dx2,dy2,d: longint;
  begin
      dx1:=b.x - a.x; dy1:=b.y - a.y;
      dx2:=c.x - a.x; dy2:=c.y - a.y;
      d:=dx1*dy2 - dx2*dy1;

      if d < 0 then exit(-1);
      if d > 0 then exit(1);
      if d = 0 then
        begin
            if (dx1*dx2 < 0) and (dy1*dy2 < 0) then exit(1);
            if dx1*dx1 + dy1*dy1 >= dx2*dx2 + dy2*dy2 then exit(0) else exit(1);
        end;
  end;

function connect(l1,l2: line): boolean;
  var A,B,C,D: point;
  begin
      A:=l1.p1; B:=l1.p2;
      C:=l2.p1; D:=l2.p2;
      if (ccw(A,B,C) * ccw(A,B,D) <= 0) and (ccw(C,D,B) * ccw(C,D,A) <= 0) then exit(true) else exit(false);
  end;

procedure dfs(u: longint);
  var v: longint;
  begin
      fre[u]:=false;
      for v:=1 to n do
        if fre[v] and c[u,v] then dfs(v);
  end;

BEGIN
    assign(f,fi); reset(f);
    read(f,n);

    for i:=1 to n do
      for j:=1 to n do c[i,j]:=false;
    for i:=1 to n do
      begin
          read(f,x1,y1,x3,y3);
          x2:=x1; y2:=y3; x4:=x3; y4:=y1;

          with tg[i] do
            begin
                canh[1].p1.x:=x1; canh[1].p1.y:=y1; canh[1].p2.x:=x2; canh[1].p2.y:=y2;
                canh[2].p1.x:=x2; canh[2].p1.y:=y2; canh[2].p2.x:=x3; canh[2].p2.y:=y3;
                canh[3].p1.x:=x3; canh[3].p1.y:=y3; canh[3].p2.x:=x4; canh[3].p2.y:=y4;
                canh[4].p1.x:=x4; canh[4].p1.y:=y4; canh[4].p2.x:=x1; canh[4].p2.y:=y1;
            end;

          for j:=i-1 downto 1 do
            begin
                for k:=1 to 4 do
                  for z:=1 to 4 do
                    if connect(tg[j].canh[k] , tg[i].canh[z]) then
                      begin
                          c[i,j]:=true;
                          c[j,i]:=true;
                          goto l1;
                      end;
                l1:
            end;
      end;

    ans:=0;
    for i:=1 to n do fre[i]:=true;
    for i:=1 to n do
      if fre[i] then
        begin
            inc(ans);
            dfs(i);
        end;

    assign(f,fo); rewrite(f); writeln(f,ans); close(f);
END.
