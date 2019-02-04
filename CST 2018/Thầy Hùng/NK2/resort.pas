const fi = 'resort.inp';
      fo = 'resort.out';
var a,lon,be: array [0..2001,0..2001] of longint;
    n,m,p,q,i,j,b,x,y,ans: longint;

procedure init;
  var f: text;
      i,j: longint;
  begin
      assign(f,fi); reset(f);
      read(f,n,m,p,q,b);
      for i:=1 to n do
        for j:=1 to m do read(f,a[i,j]);
  end;

procedure out;
  var f: text;
  begin
      assign(f,fo); rewrite(f); writeln(f,ans); close(f);
  end;

BEGIN
    init;
    fillchar(lon,sizeof(lon),0);
    fillchar(be,sizeof(be),0);
    for i:=1 to n do
      for j:=1 to m do
        begin
            lon[i,j]:=lon[i-1,j] + lon[i,j-1] - lon[i-1,j-1];
            be[i,j]:=be[i-1,j] + be[i,j-1] - be[i-1,j-1];
            if a[i,j] < b then inc(be[i,j]);
            if a[i,j] > b then inc(lon[i,j]);
        end;

    ans:=0;
    for i:=1 to n-p+1 do
      for j:=1 to m-q+1 do
        begin
            x:=be[i+p-1,j+q-1] - be[i-1,j+q-1] - be[i+p-1,j-1] + be[i-1,j-1];
            y:=lon[i+p-1,j+q-1] - lon[i-1,j+q-1] - lon[i+p-1,j-1] + lon[i-1,j-1];
            if (x < (p*q+1) div 2) and (y < p*q - (p*q+1) div 2) then inc(ans);
        end;

    out;
END.