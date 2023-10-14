const fi='vector.inp';
      fo='vector.out';
var a,b,d:array[0..1000000] of longint;
    c:array[0..1000000] of char;
    m,n,k:longint;
procedure doc;
var i,j:longint;
begin
 assign(input,fi);
 reset(input);
 read(m);
 for i:=1 to m do read(a[i]);
 read(n);
 for i:=1 to n do read(b[i]);
 while m<n do
  begin
   m:=m+1;
   a[m]:=1;
  end;
 while n<m do
  begin
   n:=n+1;
   b[n]:=1;
  end;
 close(input);
end;

procedure ghi;
var i,j,k:longint;
begin
 assign(output,fo);
 rewrite(output);
 k:=0;
 for i:=1 to n do
    begin
     k:=k+1;
     c[k]:='D';
     d[k]:=a[i];
     //---------------
     k:=k+1;
     c[k]:='D';
     d[k]:=b[i];
     //--------------
     k:=k+1;
     c[k]:='W';
     d[k]:=b[i];
     //---------------
     k:=k+1;
     c[k]:='D';
     d[k]:=a[i];
     //---------------
     k:=k+1;
     c[k]:='W';
     d[k]:=a[i];
     //-------------
     k:=k+1;
     c[k]:='L';
     d[k]:=a[i];
     //-------------
     k:=k+1;
     c[k]:='D';
     d[k]:=b[i];
     //---------------
     k:=k+1;
     c[k]:='D';
     d[k]:=b[i];
     //--------------
     k:=k+1;
     c[k]:='W';
     d[k]:=b[i];
     //-------------
     k:=k+1;
     c[k]:='L';
     d[k]:=b[i];
  end;
writeln(k);
for i:=1 to k do writeln(d[i],' ',c[i]);
close(output);
end;

begin
 doc;
 ghi;
end.