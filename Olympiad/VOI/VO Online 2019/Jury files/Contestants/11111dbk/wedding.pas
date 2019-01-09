uses math;

var
  k, n, m, md : int64;
  a, b, p : array[0..5000000] of int64;

procedure input;
  var fi : text; i : longint;
  begin
    assign(fi, 'wedding.inp'); reset(fi);
    readln(fi, k, md);
    for i := 0 to k - 1 do
      read(fi, p[i]);
    close(fi);
  end;

function check : boolean;
  var i : longint;
  begin
    fillchar(a, sizeof(a), 0);
    fillchar(b, sizeof(b), 0);
    for i := 0 to k - 1 do
      if (p[i] mod 2 = 1) then
        begin
          b[i mod m] := 1;
          a[i div m] := 1;
        end;
    for i := 0 to k - 1 do
      if (p[i] mod 2 = 0) and (a[i mod m] = 1) and (a[i div m] = 1) then
        exit (false);
    exit (true);
  end;

function pp : boolean;
  var i : longint;
  begin
    for i := 0 to k - 1 do
      if (p[i] > 1) then
        exit (false);
    for i := 1 to k do
      if (k mod i = 0) then
        begin
          n := i;
          m := k div i;
          if (check) then exit (true);
        end;
    exit (false);
  end;

procedure output;
  var fo : text; i : longint;
  begin
    assign(fo, 'wedding.out'); rewrite(fo);
    if (md > 2) then writeln(fo, 'NO')
    else if (pp) then
      begin
        writeln(fo, 'YES');
        write(fo, n, ' ');
        for i := 0 to n - 1 do write(fo, a[i],' ');
        writeln(fo);
        write(fo, m, ' ');
        for i := 0 to m - 1 do write(fo, b[i],' ');
      end
    else writeln(fo, 'NO');
    close(fo);
  end;


begin
  input;
  output;
end.