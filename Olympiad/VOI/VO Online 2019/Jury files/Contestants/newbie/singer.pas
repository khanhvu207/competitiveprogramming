uses math;

const md = 998244353;

var
  n, d, t : int64;
  res : int64;
  a, de1, de2 : array[0..7000] of longint;
  fi, fo : text;

function check : longint;
  var cnt, lde1, rde1, lde2, rde2, i : longint;
  begin
    lde1 := 0; lde2 := 0;
    rde1 := -1; rde2 := -1;
    cnt := 0;
    for i := 0 to d - 2 do
      begin
        while (rde1 >= lde1) and (a[de1[rde1]] >= a[i]) do
          rde1 := rde1 - 1;
        rde1 := rde1 + 1;
        de1[rde1] := i;
        while (rde2 >= lde2) and (a[de2[rde2]] <= a[i]) do
          rde2 := rde2 - 1;
        rde2 := rde2 + 1;
        de2[rde2] := i;
      end;
    for i := d - 1 to n do
      begin
        while (i - de1[lde1] >= d) do lde1 := lde1 + 1;
        while (i - de2[lde2] >= d) do lde2 := lde2 + 1;
        while (rde1 >= lde1) and (a[de1[rde1]] >= a[i]) do
          rde1 := rde1 - 1;
        rde1 := rde1 + 1;
        de1[rde1] := i;
        while (rde2 >= lde2) and (a[de2[rde2]] <= a[i]) do
          rde2 := rde2 - 1;
        rde2 := rde2 + 1;
        de2[rde2] := i;
        //write(i,' ', a[de1[lde1]],' ',a[de2[lde2]],'                   ');
        if (abs(a[de2[lde2]] - a[de1[lde1]]) <= 1) then cnt := cnt + 1;
      end;
    //writeln;
    //for i := 0 to n do write(a[i], ' '); writeln('       ', cnt);
    if (cnt = t) then exit (1);
    exit (0);
  end;


procedure trau(pos : longint);
  begin
    if (pos > n) then
      begin
        res := res + check;
        exit;
      end;
    a[pos] := a[pos - 1] + 1;
    trau(pos + 1);
    a[pos] := a[pos - 1] - 1;
    trau(pos + 1);
  end;

begin
  assign(fi, 'singer.inp'); reset(fi);
  readln(fi, n, d, t);
  close(fi);
  trau(1);
  assign(fo, 'singer.out'); rewrite(fo);
  writeln(fo, res);
  close(fo);
end.