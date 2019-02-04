const fi = 'CIRCLE.inp';
      fo = 'CIRCLE.out';
type sty = array [1..5000] of extended;
var f: text;
    ans,u,v,i,n: longint;
    d,x: sty;

procedure qsort(var a: sty);
  procedure sort(l,r: longint);
    var i,j: longint; x,t: extended;
    begin
        i:=l; j:=r; x:=a[(l+r) div 2];
        repeat
            while a[i] < x do inc(i);
            while x < a[j] do dec(j);
            if not(i>j) then
              begin
                  t:=a[i]; a[i]:=a[j]; a[j]:=t;
                  inc(i); dec(j);
              end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
    end;
begin
    sort(1,n);
end;

BEGIN
    assign(f,fi); reset(f);
    read(f,n);
    for i:=1 to n do
      begin
          read(f,u,v);
          x[i]:=u*u+v*v;
      end;
    for i:=1 to n do
      begin
          read(f,u,v);
          d[i]:=u*u+v*v;
      end;
    qsort(x); qsort(d);
    
    for i:=1 to n do
      if (x[i] < d[i+1]) and (d[i] < x[i+1]) then break;

    assign(f,fo); rewrite(f); 
    if x[i] > d[i] then writeln(f,sqrt(x[i]):0:6)
                   else writeln(f,sqrt(d[i]):0:6);
     close(f);
END.
