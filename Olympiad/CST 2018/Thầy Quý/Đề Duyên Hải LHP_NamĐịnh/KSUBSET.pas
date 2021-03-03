const   finp='KSUBSET.INP';
        fout='KSUBSET.OUT';

var fi,fo:text;
    f,a,s:array[1..10]of longint;
    n,k,i,j:longint;

function kt:boolean;
    var now,t,i:longint;
    begin
        now:=1;
        t:=0;
        for i:=1 to n do
            begin
                if now>k then exit(false);
                t:=t+a[f[i]];
                if (t=s[now]) then
                    begin
                        inc(now);
                        t:=0;
                    end;
            end;
        if (now=k+1) then exit(true);
        exit(false);
    end;

procedure swap(var a,b:longint);
    var tg:longint;
    begin
        tg:=a;
        a:=b;
        b:=tg;
    end;

procedure invert(l,r:longint);
    var i:longint;
    begin
        for i:=l to (l+r) div 2 do
            swap(f[i],f[r+l-i]);
    end;

begin
    assign(fi,finp);
    reset(fi);
    assign(fo,fout);
    rewrite(fo);
    readln(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
    readln(fi);
    for i:=1 to k do read(fi,s[i]);
    for i:=1 to n do f[i]:=i;
    if kt then
        begin
            writeln(fo,'YES');
            close(fi);
            close(fo);
            exit;
        end;
    while true do
        begin
            for i:=n-1 downto 1 do
                if f[i]<f[i+1] then break;
            if f[i]>f[i+1] then break;
            for j:=n downto i+1 do
                if (f[j]>f[i]) then break;
            swap(f[i],f[j]);
            invert(i+1,n);
            if kt then
                begin
                    writeln(fo,'YES');
                    close(fi);
                    close(fo);
                    exit;
                end;
        end;
    writeln(fo,'NO');
    close(fi);
    close(fo);
end.
