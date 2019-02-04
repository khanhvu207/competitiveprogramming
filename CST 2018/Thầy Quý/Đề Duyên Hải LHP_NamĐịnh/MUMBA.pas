const fi = 'mumba.inp';
      fo = 'mumba.out';
var x: array [0..100] of byte;
    n,ans: longint;
    f: text;

function same(l,n: longint): boolean;
  var k,i,j,z: longint;
  begin
      i:=n; j:=n-l; z:=n-2*l;
      for k:=1 to l do
        if (x[i-k+1]<>x[j-k+1]) or (x[i-k+1]<>x[z-k+1]) or (x[j-k+1]<>x[z-k+1]) then exit(false);
      exit(true);
  end;

function check(n: longint): boolean;
  var l: longint;
  begin
      for l:=1 to n div 3 do
        if same(l,n) then exit(false);
      exit(true);
  end;

function tinh(i,last: longint): int64;
  begin
      if i>n then exit(1);

      tinh:=0;
      if last = 1 then
        begin
            x[i]:=0;
            if check(i) then tinh:=tinh + tinh(i+1,0)
        end
      else begin
               x[i]:=1;
               if check(i) then tinh:=tinh + tinh(i+1,1);
               x[i]:=0;
               if check(i) then tinh:=tinh + tinh(i+1,0)
           end;
  end;

BEGIN
    assign(f,fi); reset(f); readln(f,n); close(f);

    ans:=0;
    if n<=16 then
      begin
          x[1]:=0;
          ans:=tinh(2,0);
          x[1]:=1;
          ans:=ans + tinh(2,1);
      end;

    assign(f,fo); rewrite(f); writeln(f,ans); close(f);
END.