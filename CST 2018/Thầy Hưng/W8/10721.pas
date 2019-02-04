const fi = '10721.inp';
      fo = '10721.out';
var f,g: text;
    dp: array [0..51,0..51] of int64;
    n,k,m,i,j,z: longint;

BEGIN
    assign(f,fi); reset(f);
    assign(g,fo); rewrite(g);

    while not seekeof(f) do
      begin
          read(f,n,k,m);
          fillchar(dp,sizeof(dp),0);
          dp[0,0]:=1;
          for i:=1 to k do
            for j:=1 to n do
              for z:=1 to m do
                if j-z >= 0 then dp[i,j]:=dp[i,j] + dp[i-1,j-z];
          writeln(g,dp[k,n]);
      end;

    close(g);
END.