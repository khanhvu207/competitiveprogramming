uses math;

type
  list = array[0..100005] of int64;

var
  n : longint;
  x1, y1, x2, y2, r1, c1, r2, c2, sr1, sr2, sc1, sc2 : list;
  res, xx, yy : int64;

procedure input;
  var
    i : longint;
    fi : text;
  begin
    assign(fi, 'tigersuger.inp'); reset(fi);
    readln(fi, n);
    for i := 1 to n do
      begin
        readln(fi, x1[i], y1[i], x2[i], y2[i]);
        r1[i] := y1[i];
        c1[i] := x1[i];
        r2[i] := y2[i];
        c2[i] := x2[i];
      end;
    close(fi);
  end;

procedure sort(var a : list; l, r : longint);
  var
    x, i, j, tmp : int64;
  begin
    if l >= r then exit;
    x := a[random(r - l + 1) + l];
    i := l;
    j := r;
    while (i <= j) do
      begin
        while (a[i] < x) do i := i + 1;
        while (a[j] > x) do j := j - 1;
        if (i <= j) then
          begin
            tmp := a[i]; a[i] := a[j]; a[j] := tmp;
            i := i + 1;
            j := j - 1;
          end;
      end;
    sort(a, l, j);
    sort(a, i, r);
  end;

procedure init(var a, sa : list);
  var i : longint;
  begin
    for i := 1 to n do
      sa[i] := sa[i - 1] + a[i];
  end;

function bn(var a : list; l, r, val : longint) : longint;
  var mid : longint;
  begin
    if (l >= r - 1) then
      begin
        if (a[l] >= val) then exit (l);
        if (a[r] >= val) then exit (r);
        exit (r + 1);
      end;
    mid := (l + r) div 2;
    if (a[mid] >= val) then exit (bn(a, l, mid, val));
    exit (bn(a, mid, r, val));
  end;

function check(x, y : int64) : int64;
  var res, pos : int64;
  begin
    pos := bn(r1, 1, n, y) - 1;
    res := 0;
    //writeln(x, ' ', y); write('     ', pos);
    if (pos >= 0) then
      res := res + sr1[n] - sr1[pos] - y * (n - pos); //write(' ', res);
    pos := bn(c1, 1, n, x) - 1;
    //write(' ', pos);
    if (pos >= 0) then
      res := res + sc1[n] - sc1[pos] - x * (n - pos);  //write(' ', res);
    pos := bn(r2, 1, n, y) - 1;
    //write(' ', pos);
    if (pos >= 0) then
      res := res + y * pos - sr2[pos];                 //write(' ', res);
    pos := bn(c2, 1, n, x) - 1;
    //write(' ', pos);
    if (pos >= 0) then
      res := res + x * pos - sc2[pos];                 //write(' ', res);
    //writeln;
    //writeln(x, ' ', y, ' ', res);
    exit (res);
  end;

procedure minimize(val : int64; x, y : longint);
  begin
    if (val >= res) then exit;
    res := val;
    xx := x;
    yy := y;
  end;

procedure pp;
  var i : longint;
  begin
    for i := 1 to n do
      begin
        minimize(check(x1[i], y1[i]), x1[i], y1[i]);
        minimize(check(x1[i], y2[i]), x1[i], y2[i]);
        minimize(check(x2[i], y1[i]), x2[i], y1[i]);
        minimize(check(x2[i], y2[i]), x2[i], y2[i]);
      end;
  end;

procedure output;
  var fo : text; i : longint;
  begin
    assign(fo, 'tigersuger.out'); rewrite(fo);
    writeln(fo, res);
    writeln(fo, xx, ' ', yy);
    for i := 1 to n do
      begin
        if (xx >= x1[i]) and (xx <= x2[i]) then
          write(fo, xx, ' ')
        else if (xx < x1[i]) then
          write(fo, x1[i], ' ')
        else
          write(fo, x2[i]);
        if (yy >= y1[i]) and (yy <= y2[i]) then
          write(fo, yy)
        else if (yy < y1[i]) then
          write(fo, y1[i])
        else
          write(fo, y2[i]);
        writeln(fo);
      end;
    close(fo);
    {
    for i := 1 to n do write(r1[i],' '); writeln;
    for i := 1 to n do write(r2[i],' '); writeln;
    for i := 1 to n do write(c1[i],' '); writeln;
    for i := 1 to n do write(c2[i],' '); writeln;
    writeln;
     for i := 1 to n do write(sr1[i],' '); writeln;
    for i := 1 to n do write(sr2[i],' '); writeln;
    for i := 1 to n do write(sc1[i],' '); writeln;
    for i := 1 to n do write(sc2[i],' '); writeln;
    }
  end;

begin
  input;
  sort(r1, 1, n);  init(r1, sr1);
  sort(r2, 1, n);  init(r2, sr2);
  sort(c1, 1, n);  init(c1, sc1);
  sort(c2, 1, n);  init(c2, sc2);
  res := 1000000000000000;
  pp;
  output;
end.