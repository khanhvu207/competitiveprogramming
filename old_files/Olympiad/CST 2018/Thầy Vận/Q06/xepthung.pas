const fi = 'xepthung.inp';
      fo = 'xepthung.out';
var a,l,r: array [0..10001] of longint;
    m,n,i: longint;
    f: text;

function xl: boolean;
  var tmp,i: longint;
  begin
      tmp:=0;
      for i:=m downto 0 do
        begin
            tmp:=tmp - l[i];
            if tmp < 0 then exit(false);
            tmp:=tmp + r[i];
        end;
      exit(true);
  end;

BEGIN
    assign(f,fi); reset(f);
    read(f,m,n);
    for i:=1 to n do read(f,a[i]);
    
    fillchar(l,sizeof(l),0);
    fillchar(r,sizeof(r),0);
    for i:=1 to n div 2 do
      begin
          inc(l[a[i]]);
          inc(r[a[n div 2 + i]]);
      end;

    for i:=n div 2 downto 0 do
      begin   
          if xl then break;
          dec(l[a[i]]);
          inc(r[a[i]]);
          dec(r[a[2*i]]);
          dec(r[a[2*i-1]]);
      end;

    assign(f,fo); rewrite(f); writeln(f,i); close(f);
END.


