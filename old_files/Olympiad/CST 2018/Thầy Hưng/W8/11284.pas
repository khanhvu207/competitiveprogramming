//TLE
uses math;
const fi = '11284.inp';
      fo = '11284.out';
var f,g: text;
    d,c: array [0..50,0..50] of real;
    a: array [0..50] of longint;
    save: array [0..50] of real;
    fre: array [0..50] of boolean;
    ans, total: real;
    n,m,i,j,k,u,v: longint;

procedure dfs(u: longint; sumsave,sum: real; k: longint);
  var i: longint;
  begin
      if total - sum <= ans then exit;
      if d[u,0] < maxlongint then if sumsave - sum - d[u,0] > ans then ans:=sumsave -sum - d[v,0];
      if k=m then exit;

      for i:=1 to n do
        if fre[i] or (d[u,i] >= maxlongint) then continue
        else begin
                 fre[i]:=true;
                 dfs(i, sumsave + save[i], sum + d[u,i], k+1);
                 fre[i]:=false;
             end;
  end;

BEGIN
    assign(f,fi); reset(f);
    assign(g,fo); rewrite(g);

    read(f,n);
while not seekeof(f) do
begin
    read(f,n,m);
    for i:=0 to n do
      for j:=0 to n do
        if i=j then d[i,j]:=0 else d[i,j]:=maxlongint;
    for i:=1 to m do
      begin
          read(f,u,v,ans);
          d[u,v]:=min(d[u,v],ans);
          d[v,u]:=d[u,v];
      end;

    read(f,m);
    total:=0;
    fillchar(fre,sizeof(fre),true);
    fillchar(save,sizeof(save),0);
    for i:=1 to m do
      begin
          read(f,u,ans);
          save[u]:=save[u] + ans;
          fre[u]:=false;
          total:=total + ans;
      end;

    for k:=0 to n do
      for i:=0 to n do
        for j:=0 to n do
          d[i,j]:=min(d[i,j] , d[i,k] + d[k,j]);

    ans:=0;
    dfs(0,0,0,0);

    if ans <= 0  then writeln(g,'Don''t leave the house') else writeln(g,'Daniel can save $',ans:0:2);
end;

    close(g);
END.