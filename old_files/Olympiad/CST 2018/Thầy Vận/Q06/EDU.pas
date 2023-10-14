const fi = 'EDU.INP';
      fo = 'EDU.OUT';

var f: text;
    dp: array [0..71,0..71] of int64;
    n,t,p,smax: longint;

function tinh(i,sum: longint): int64;
  var j: longint;
      re: int64;
  begin
      if dp[i,sum]<>-1 then exit(dp[i,sum]);
      if sum > t then exit(0);
      if i>n then
        if sum = t then begin dp[i,sum]:=1; exit(1); end
                   else begin dp[i,sum]:=0; exit(0); end;

      re:=0;
      for j:=p to t-sum do
        re:=re + tinh(i+1, sum + j);

      dp[i,sum]:=re;
      exit(re);
  end;


BEGIN
    assign(f,fi); reset(f); read(f,n,t,p); close(f);
    fillchar(dp,sizeof(dp),255);
    assign(f,fo); rewrite(f); writeln(f,tinh(1,0)); close(f);
END.
