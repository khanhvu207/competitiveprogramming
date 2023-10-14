const fi = 'fire.inp';
      fo = 'fire.out';
var f: text;
    n,i,min,dem,x,h: longint;
    a: array [0..500010] of longint;

BEGIN
    assign(f,fi); reset(f);

    read(f,n,h);
    fillchar(a,sizeof(a),0);
    for i:=1 to n do
      begin
          read(f,x);
          if odd(i) then begin inc(a[0]); dec(a[x+1]); end else inc(a[h-x+1]);
      end;

    min:=maxlongint; dem:=0;
    for i:=1 to h do
      begin
          a[i]:=a[i-1] + a[i];
          if a[i] < min then begin min:=a[i]; dem:=1; end
          else if a[i] = min then inc(dem);
      end;

    assign(f,fo); rewrite(f); writeln(f,min,' ',dem); close(f);
END.
