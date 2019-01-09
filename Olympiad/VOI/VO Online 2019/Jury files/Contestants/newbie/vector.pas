const
  maxval = 1000000;
  maxp = 10000000;

type
  list = array[0..maxval] of longint;

var
  ta, tb : list;
  p : array[0..1000000] of int64;
  ch : array[0..1000000] of char;
  n, m, val, a, b, cnt : int64;
  i : longint;
  fi, fo : text;

procedure init(var val : int64; var cnt : list);
  var i : int64;
  begin
    i := 2;
    while (true) do
      begin
        if (i * i > val) then break;
        while (val mod i = 0) do
          begin
            cnt[i] := cnt[i] + 1;
            val := val div i;
          end;
        i := i + 1;
      end;
    if (val <= maxval) then
      begin
        cnt[val] := cnt[val] + 1;
        val := 1;
      end;
  end;

procedure add_res(val : int64; c : char);
  begin
    cnt := cnt + 1;
    p[cnt] := val;
    ch[cnt] := c;
  end;

begin
  assign(fi, 'vector.inp'); reset(fi);
  a := 1; b := 1;
  readln(fi, m);
  for i := 1 to m do
    begin
      read(fi, val);
      a := a * val;
    end;
  readln(fi, n);
  for i := 1 to n do
    begin
      read(fi, val);
      b := b * val;
    end;
  close(fi);
  init(a, ta);
  init(b, tb);
  if (b > 1) and (b <= maxp) then
    begin
      add_res(b, 'D');
      add_res(b, 'W');
    end;
  if (b > 1) then begin
  add_res(b, 'D'); add_res(b, 'D'); add_res(b, 'W'); add_res(b, 'L');
  end;
  if (a > 10) then begin
  add_res(a, 'D'); add_res(a, 'D'); add_res(a, 'W'); add_res(a, 'L');
  end;
  for i := 2 to maxval do
    begin
      if (tb[i] mod 2 = 1) then
        begin
          add_res(i, 'D');
          tb[i] := tb[i] + 1;
        end;
      while (tb[i] > 0) do
        begin
          add_res(i, 'W');
          tb[i] := tb[i] - 2;
          ta[i] := ta[i] + 1;
        end;
    end;
  for i := 2 to maxval do
    begin
      if (ta[i] mod 2 = 1) then
        begin
          add_res(i, 'D');
          add_res(i, 'D');
          add_res(i, 'W');
          ta[i] := ta[i] + 1;
        end;
      while (ta[i] > 0) do
        begin
          add_res(i, 'L');
          ta[i] := ta[i] - 2;
        end;
    end;
  assign(fo, 'vector.out'); rewrite(fo);
  writeln(fo, cnt);
  for i := 1 to cnt do
    writeln(fo, p[i], ' ', ch[i]);
  close(fo);
end.