Uses crt;
const
        maxn=100000;maxx=1000000000;
        fi='TIGERSUGER.INP';fo='TIGERSUGER.OUT';
var
        f:text;
        n,i,j,k,x,y,tt,tam,resw,resx,resy:longint;
        s1,s2,minx,miny:int64;
        a,b,c,d,a2,b2,c2,d2:array[0..maxn] of longint;
procedure sort(l,r:longint; var a:array of longint);
var
        i,j,x,y:longint;
begin
        i:=l;j:=r;x:=a[(l+r) div 2];
        repeat
                while a[i]<x do inc(i);
                while x<a[j] do dec(j);
                if (i<=j) then
                begin
                        y:=a[i];a[i]:=a[j];a[j]:=y;
                        inc(i);dec(j);
                end;
        until i>j;
        if l<j then sort(l,j,a);
        if i<r then sort(i,r,a);
end;
procedure tinh(i:longint);
var
        cc,cl:array[0..4] of longint;
begin
        cc[1]:=a2[i];cc[2]:=b2[i];cc[3]:=resx;
        cl[1]:=c2[i];cl[2]:=d2[i];cl[3]:=resy;
        sort(1,3,cc);sort(1,3,cl);
        x:=cc[2];y:=cl[2];
end;
begin
        assign(f,fi);reset(f);
        readln(f,n);
        for i:=1 to n do begin
        readln(f,a[i],c[i],b[i],d[i]);
        a2[i]:=a[i];b2[i]:=b[i];c2[i]:=c[i];d2[i]:=d[i];end;
        close(f);

        sort(1,n,a);sort(1,n,b);sort(1,n,c);sort(1,n,d);

        for i:=1 to n do begin
        s1:=s1+a[i]+1;s2:=s2+c[i]+1;end;

        j:=0;k:=0;a[0]:=0;b[0]:=0;a[n+1]:=maxx+1;b[n+1]:=maxx+1;minx:=maxx*100000+1;
        tt:=0;tam:=-1;
        repeat
                tt:=tam;
                if (a[j+1]<b[k+1]) and(j<n) then
                begin
                        inc(j);tam:=a[j];
                end
                else
                begin
                        inc(k);tam:=b[k];
                end;
                s1:=s1+(tam-tt)*(-n+j+k-1);
                if (abs(s1)<minx) {and (tam>=tt)} then
                begin
                        minx:=abs(s1);
                        resx:=tam;
                end;
        until (j=n) and (k=n);
        j:=0;k:=0;c[0]:=0;d[0]:=0;c[n+1]:=maxx+1;d[n+1]:=maxx+1;miny:=maxx*100000+1;
        tt:=0;tam:=-1;
        repeat
                tt:=tam;
                if (c[j+1]<d[k+1]) and(j<n) then
                begin
                        inc(j);tam:=c[j];
                end
                else
                begin
                        inc(k);tam:=d[k];
                end;
                s2:=s2+(tam-tt)*(-n+j+k-1);
                if (s2<miny) {and (tam>=tt)} then
                begin
                        miny:=s2;
                        resy:=tam;
                end;
        until (j=n) and (k=n);
        for i:=1 to n do begin
        tinh(i);resw:=resw+abs(resx-x)+abs(resy-y);end;
        assign(f,fo);rewrite(f);
        writeln(f,resw);
        for i:=1 to n do begin
        tinh(i);writeln(f,x,' ',y);end;
        close(f);
end.
