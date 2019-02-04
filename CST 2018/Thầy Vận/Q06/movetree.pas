const fi = 'movetree.inp';
      fo = 'movetree.out';

type sty = record
         x,y,tt: longint;
     end;

var endp: sty;
    n,ans: longint;
    q: array [1..42*42] of sty;
    s: array [1..40,1..40] of char;
    bac: array [1..42*42] of longint;
    fre: array [1..40,1..40,0..1] of boolean;

procedure init;
  var f: text;
      i: longint;
  begin
      assign(f,fi); reset(f);
      readln(f,n);
      for i:=1 to n do readln(f,s[i]);
      close(f);
  end;
procedure abcxyz;
  var i,j: longint;
  begin
      for i:=1 to n do
        for j:=1 to n do
          if s[i,j]='e' then
            begin
                if (1 <= i+1) and (i+1 <= n) and (s[i+1,j]='e') then begin endp.x:=i+1; endp.y:=j; endp.tt:=0; end
                else if (1 <= j+1) and (j+1 <= n) and (s[i,j+1]='e') then begin endp.x:=i; endp.y:=j+1; endp.tt:=1; end;
                exit;
            end;
  end;
procedure out;
  var f: text;
  begin
      assign(f,fo); rewrite(f); writeln(f,ans); close(f);
  end;

function okk(a,b,u,v,x,y: longint): boolean; begin
        if (s[a,b]='1') or (s[u,v]='1') or (s[x,y]='1') then exit(false); exit(true);
end;
function ok(a: longint): boolean; begin
        if (1 <= a) and (a <= n) then exit(true) else exit(false);
end;
function check(a,b,u,v,x,y,d: longint): boolean; begin
        if ok(a) and ok(b) and ok(u) and ok(v) and ok(x) and ok(y) and fre[u,v,d] and okk(a,b,u,v,x,y) then exit(true) else exit(false);
end;

procedure queue;
  var f,l,u,v,d,tmp: longint;

  begin
      ans:=0; f:=1; l:=1;
      with q[1] do begin x:=1; y:=2; tt:=1; end; bac[f]:=0;
      fillchar(fre,sizeof(fre),true); fre[1,2,1]:=false;

      repeat
          u:=q[f].x; v:=q[f].y; d:=q[f].tt; tmp:=bac[f]; inc(f);

          if (u = endp.x) and (v = endp.y) and (d = endp.tt) then begin ans:=tmp; exit; end;

          if d=1 then
            begin
                if check(u-1,v-1,u-1,v,u-1,v+1,1) then begin
                        inc(l); with q[l] do begin x:=u-1; y:=v; tt:=1; end;
                        bac[l]:=tmp + 1; fre[u-1,v,1]:=false;
                end;
                if check(u+1,v-1,u+1,v,u+1,v+1,1) then begin
                        inc(l); with q[l] do begin x:=u+1; y:=v; tt:=1; end;
                        bac[l]:=tmp + 1; fre[u+1,v,1]:=false;
                end;
                if check(u,v,u,v+1,u,v+2,1) then begin
                        inc(l); with q[l] do begin x:=u; y:=v+1; tt:=1; end;
                        bac[l]:=tmp + 1; fre[u,v+1,1]:=false;
                end;
                if check(u,v-2,u,v-1,u,v,1) then begin
                        inc(l); with q[l] do begin x:=u; y:=v-1; tt:=1; end;
                        bac[l]:=tmp + 1; fre[u,v-1,1]:=false;
                end;
                if ok(u-1) and ok(v-1) and ok(u-1) and ok(v) and ok(u-1) and ok(v+1) and
                   ok(u+1) and ok(v-1) and ok(u+1) and ok(v) and ok(u+1) and ok(v+1) and
                   okk(u-1,v-1,u-1,v,u-1,v+1) and okk(u+1,v-1,u+1,v,u+1,v+1) and fre[u,v,0] then
                   begin
                       inc(l); with q[l] do begin x:=u; y:=v; tt:=0; end;
                       bac[l]:=tmp + 1; fre[u,v,0]:=false;
                   end;
            end
          else
            begin
                if check(u-1,v-1,u,v-1,u+1,v-1,0) then begin
                        inc(l); with q[l] do begin x:=u; y:=v-1; tt:=0; end;
                        bac[l]:=tmp + 1; fre[u,v-1,0]:=false;
                end;
                if check(u-1,v+1,u,v+1,u+1,v+1,0) then begin
                        inc(l); with q[l] do begin x:=u; y:=v+1; tt:=0; end;
                        bac[l]:=tmp + 1; fre[u,v+1,0]:=false;
                end;
                if check(u,v,u+1,v,u+2,v,0) then begin
                        inc(l); with q[l] do begin x:=u+1; y:=v; tt:=0; end;
                        bac[l]:=tmp + 1; fre[u+1,v,0]:=false;
                end;
                if check(u-2,v,u-1,v,u,v,0) then begin
                        inc(l); with q[l] do begin x:=u-1; y:=v; tt:=0; end;
                        bac[l]:=tmp + 1; fre[u-1,v,0]:=false;
                end;
                if ok(u-1) and ok(v-1) and ok(u) and ok(v-1) and ok(u+1) and ok(v-1) and
                   ok(u-1) and ok(v+1) and ok(u) and ok(v+1) and ok(u+1) and ok(v+1) and
                   okk(u-1,v-1,u,v-1,u+1,v-1) and okk(u-1,v+1,u,v+1,u+1,v+1) and fre[u,v,1] then
                   begin
                       inc(l); with q[l] do begin x:=u; y:=v; tt:=1; end;
                       bac[l]:=tmp + 1; fre[u,v,1]:=false;
                   end;
            end;
      until f>l;
  end;

BEGIN
    init;
    abcxyz;
    queue;
    out;
END.
