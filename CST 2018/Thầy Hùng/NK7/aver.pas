uses math;
const fi = 'aver.inp';
      fo = 'aver.out';
var f: text;
    i: longint;
    n,k,ans,tmp: int64;
    a,b: array [0..1000000] of int64;

procedure sort(l,r: longint);
      var
         i,j,x,y,x1: int64;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         x1:=b[(l+r) div 2];
         repeat
           while (a[i]<x) or ((a[i]=x) and (b[i]<x1)) do
            inc(i);
           while (x<a[j]) or ((a[j]=x) and (b[j]>x1)) do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];a[i]:=a[j];a[j]:=y;
                y:=b[i];b[i]:=b[j];b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin
    assign(f,fi);reset(f);
    read(f,n,k);
    a[0]:=0;
    for i:=1 to n do
      begin
          read(f,a[i]);
          a[i]:=a[i-1]+a[i];
      end;
    for i:=0 to n  do
      begin
          a[i]:=a[i]-k*i;
          b[i]:=i;
      end;
    sort(0,n);

    ans:=0; tmp:=b[0];
    for i:=2 to n do
      begin
          ans:=max(ans , b[i] - tmp);
          tmp:=min(b[i] , tmp);
      end;

    assign(f,fo); rewrite(f); writeln(f,ans); close(f);
end.

