uses math;
const fi = 'GPS.INP';
      fo = '';
var f,g: text;
    n,m,i,j,k,t: longint;
    s,x: ansistring;
    dp: array [0..500,0..500] of longint;

function tinh(i,j: longint): integer;
  begin
      if s[i]=x[j] then exit(2) else exit(-1);
  end;

BEGIN
    assign(f,fi); reset(f);
    assign(g,fo); rewrite(g);
    readln(f,t);

    repeat dec(t);
        readln(f,s); readln(f,x);

        n:=length(s); m:=length(x);
        for i:=1 to n do dp[i,0]:=-i-4;
        for i:=1 to m do dp[0,i]:=-i-4;

        for i:=1 to n do
          for j:=1 to m do
            begin
                dp[i,j]:=dp[i-1,j-1] + tinh(i,j);
                for k:=1 to i-1 do dp[i,j]:= max(dp[i,j], tinh(k,j) + dp[k-1,j-1] -4-(i-k));
                for K:=1 to j-1 do dp[i,j]:= max(dp[i,j], tinh(i,k) + dp[i-1,k-1] -4-(j-k));
            end;

        writeln(g,dp[n,m]);
    until t=0;
    close(g);
END.