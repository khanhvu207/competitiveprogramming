const fi = 'trees.inp';
      fo = 'trees.out';
var f: text;
    n,i: longint;
    ans: int64;
    a,b: array [0..100000] of longint;

function uc(a,b: longint): longint;
  begin
      if b=0 then exit(a);
      exit(uc(b, a mod b));
  end;

BEGIN
    assign(f,fi); reset(f);
    read(f,n);
    for i:=1 to n do read(f,a[i],b[i]);
    a[0]:=a[n]; b[0]:=b[n];

    ans:=0;
    for i:=1 to n do ans:=ans + uc(abs(a[i]-a[i-1]),abs(b[i]-b[i-1]));

    assign(f,fo); rewrite(f); writeln(f,ans); close(f);
END.