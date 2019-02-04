const fi = 'PPOINT.INP';
      fo = 'PPOINT.OUT';
var f: text;
    n,m,i,j,tmp,dpt : LongInt;
    a,lua,b,t: array [0..100001] of longint;
    free: array [0..100001] of boolean;
    dk: boolean;

procedure sort (l,r : LongInt);
  var i,j,x,t: LongInt;
  begin
      if l>=r then exit;
      i:=l; j:=r; x:=a[(l+r) div 2];
      repeat
          while a[i] < x do inc(i);
          while a[j] > x do dec(j);
          if not(i > j) then
            begin
                t:=a[i]; a[i]:=a[j]; a[j]:=t;
                inc(i); dec(j);
            end;
      until i > j;
      sort(l,j);
      sort(i,r);
    end;

procedure init;
  begin
      assign(f,fi); reset(f);
      readln(f,n);
      m:=n*(n-1) div 2;
      for i:=1 to m do read(f,a[i]);
      sort(1,m);
  end;

function check (top,gt: longint): boolean;
  var i: longint;
  begin
      if lua[a[m] - gt] = 0 then exit(false);
      for i:=1 to top do
        if lua[gt - b[t[i]]] = 0 then exit(false);
      exit(true);
  end;

procedure update(top,gt: LongInt);
  var i: Longint;
  begin
        dec(lua[a[m] - gt]);
        for i:=1 to top do dec(lua[gt - b[t[i]]]);
  end;

procedure update2(top,gt: longint);
  var i: LongInt;
  begin
      inc(lua[a[m] - gt]);
      for i:=1 to top do inc(lua[gt - b[t[i]]]);
  end;

procedure try(x: longint);
  var i: longint;
  begin
      if x = n-1 then
        begin
            for i:=1 to x do write(f,b[t[i]],' ');
            write(f,a[m]);
            close(f);
            halt;
        end;

      for i:=t[x] to tmp do
        if check(x , b[i]) then
          begin
              inc(dpt, 2*x);
              update(x , b[i]);
              t[x + 1]:=i;
              try(x + 1);
              update2(x , b[i]);
          end;
  end;

BEGIN
    init;

    fillchar(lua,sizeof(lua),0);
    for i:=1 to m do inc(lua[a[i]]);

    tmp:=0;
    for i:=1 to m do
      if (a[i-1] < a[i]) and (lua[a[m] - a[i]] > 0) then
        begin
            inc(tmp);
            b[tmp]:=a[i];
        end;

    assign(f,fo); rewrite(f);
    try(0);

    writeln(f,-1); close(f);
END.