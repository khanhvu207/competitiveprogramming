uses crt;
const
    fi='wedding.inp';
    fo='wedding.out';
var
    p,s,t: array[0..15*trunc(1e5)] of longint;
    k,m,n,nt: longint;
    procedure docf;
    var
        f: text;
        i: longint;
    begin
        assign(f,fi);
        reset(f);
        readln(f,k,nt);
        for i:=0 to k-1 do
            read(f,p[i]);
        close(f);
    end;
    procedure xuly;
    var
        i,j: longint; kt: boolean;
    begin
        randomize;
        repeat
            m:=random(k div 2+1);
            n:=random(k div 2+1);
            if m*n=k then
            repeat
                for i:=1 to m do
                    s[i]:=random(nt);
                for i:=1 to n do
                    t[i]:=random(nt);
                kt:=true;
                for i:=1 to m do
                begin
                    for j:=1 to n do
                        if s[i]*t[j]-p[i*n+j] mod nt<>0 then
                        begin
                            kt:=false;
                            break;
                        end;
                    if not kt then  break;
                end;
            until kt;
        until false;
    end;
    procedure xuat;
    var
        f: text;
        i: longint;
    begin
        assign(f,fo);
        rewrite(f);
        writeln(f,'YES');
        for i:=1 to m do
            write(f,s[i],' ');
        writeln(f);
        for i:=1 to n do
            write(f,t[i],' ');
        close(f);
    end;
begin
    docf;
    xuly;
    xuat;
end.