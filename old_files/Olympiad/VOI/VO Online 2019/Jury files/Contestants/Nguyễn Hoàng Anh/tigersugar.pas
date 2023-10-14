uses math;
const
    fi='tigersugar.inp';
    fo='tigersugar.out';
    lim=trunc(1e5);
type
    descartes=record
        x,y: longint;
    end;
    rectangle=record
        r1,r2: descartes;
    end;
var
    f: text;
    a: array[1..lim] of rectangle;
    b,b1: array[1..lim] of descartes;
    res: descartes;
    xmin,xmax,ymin,ymax,d: longint;
    n: integer;
    procedure Readf;
    var
        i: integer;
    begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            with a[i] do
            begin
                readln(f,r1.x,r1.y,r2.x,r2.y);
                if (xmin>r1.x) or (i=1) then
                    xmin:=r1.x;
                if (xmax<r2.x) or (i=1) then
                    xmax:=r2.x;
                if (ymin>r1.y) or (i=1) then
                    ymin:=r1.y;
                if (ymax<r2.y) or (i=2) then
                    ymax:=r2.y;
            end;
        close(f);
    end;
    procedure run;
    var
        i,j,k,d1,x,y,p: longint;
    begin
        d:=trunc(1e9);
        for i:=xmin to xmax do
            for j:=ymax downto ymin do
            begin
                d1:=0;
                for k:=1 to n do
                begin
                    p:=trunc(1e9);
                    for x:=a[k].r1.x to a[k].r2.x do
                        for y:=a[k].r1.y to a[k].r2.y do
                            if p>abs(i-x)+abs(j-y) then
                            begin
                                p:=abs(i-x)+abs(j-y);
                                b1[k].x:=x; b1[k].y:=y;
                            end;
                    inc(d1,p);
                end;
                if d1<d then
                begin
                    d:=d1;
                    res.x:=i; res.y:=j;
                    b:=b1;
                end;
            end;
    end;
    procedure Writef;
    var
        i: longint;
    begin
        assign(f,fo);
        rewrite(f);
        writeln(f,d);
        writeln(f,res.x,' ',res.y);
        for i:=1 to n do
            writeln(f,b[i].x,' ',b[i].y);
        close(f);
    end;
begin
    Readf;
    Run;
    Writef;
end.
