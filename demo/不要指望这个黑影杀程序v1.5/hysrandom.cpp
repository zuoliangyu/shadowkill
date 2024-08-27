#include <bits/stdc++.h>
#include <graphics.h>

#define HB 1200.0
#define VB 960.0
#define STP stp[pid == PLS]
#define POSPx(i) rms[pos[i]].x + 60 + offst[i][psiz[i]]
#define POSPy(i) rms[pos[i]].y + 60 + offst[i][psiz[i]]
#define hashx(s) (s[0] + 100 * s[1] + 10000 * s[2] + 1000000 * s[3])
using namespace std;
double pi = 3.141592653589793238462643383279;
int ROOM, PLS, N, M, FS, NRM = -1, sta[999], ROUND = -2, STGO = 1, NHB, CUBETURN, LINE, NCPL, MODF, TAGS[999], STRM, READYRESET, mdtag1, flag1, flag2, pos[999], dor[999][999], dis[999], stp[2], psiz[99], dead[999], poison[999], discov[999][997];
int rmcnt[999], offst[999][999], orirm[999], transed[999], rmgm[999], GMS = 0;
PIMAGE DESK, OTTA;
double ani, STLV;
mouse_msg msg = { 0 }, lmsg = { 0 };
key_msg ksg = { 0 };
string name[999];
int nstp = 1;
struct tag {
    int type;
    string msg;
};
struct gim {
    int rom, pl, st;
    double lv;
    string name;
} gms[99];
vector<tag> tags[999];
vector<int> pat[99];
struct room {
    int x, y, h, w;
    string name;
} rms[999];
void save(string);
void load(string);
int db(double x, double y, double w, double h, string str, int c1, int c3 = 0, int c2 = -1)
{
    if (!~c2)
        c2 = c1;
    setfillcolor(c3);
    ege_fillrect(x - w / 2, y - h / 2, w, h);
    setcolor(0xff0000000 ^ c1);
    ege_rectangle(x - w / 2, y - h / 2, w, h);
    setcolor(c2);
    outtextxy(x, y, str.c_str());
    if (abs(msg.x - x) < w / 2 && abs(msg.y - y) < h / 2 && msg.is_down() - lmsg.is_down() > 0) {
        return 1;
    }
    return 0;
}
string n2s(int num)
{
    if (num < 0)
        return "-" + n2s(-num);
    string s = "0";
    s[0] = '0' + num % 10;
    if (num < 10)
        return s;
    else
        return n2s(num / 10) + s;
}
void title()
{
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setbkmode(TRANSPARENT);
    ege_enable_aa(true);
    setbkcolor(0xff000000);
    setfont(-120, 0, "Î¢ÈíÑÅºÚ");
    setcolor(hsv2rgb(0, 1, 1));
    outtextxy(HB / 2, VB / 4, "ºÚÓ°É±");
    setlinewidth(6);
    setfont(-60, 0, "Î¢ÈíÑÅºÚ");
    if (db(HB / 2, VB / 4 * 3, 320, 90, "¿ªÊ¼ÓÎÏ·", hsv2rgb(0, 1, 1))) {
        ROOM = 1;
    }
}
void bfs(int beg, int stp)
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
        dis[i] = stp + 1;
    dis[beg] = 0;
    q.push(beg);
    while (q.size()) {
        int now = q.front();
        q.pop();
        if (now == 24 && !flag1 && now != beg)
            continue;
        if (now == 1 && !flag2 && now != beg)
            continue;
        for (int i = 1; i <= N; i++) {
            if (dor[now][i] && dis[i] > dis[now] + 1) {
                dis[i] = dis[now] + 1;
                q.push(i);
            }
        }
    }
    //	for(int i=1;i<=N;i++){
    //		printf("%d ",dis[i]);printf("\n");
    //	}
}
void kp(int crus)
{
    string ss2;
    char ss1[55] = "";
    ss2 = "ÕæµÄÒªÉ±ËÀ½ÇÉ«¡°" + name[crus] + "¡±Âð£¿£¡£¨Y/N£©";
    inputbox_getline("µ¶ÈË»·½Ú", ss2.c_str(), ss1, 50);
    if (ss1[0] == 'Y') {
        //		printf("¡¾%s¡¿¶¯Ïò\n",name[crus].c_str());
        //		for(int j=0;j<=psiz[crus];j++){
        //			printf("¡¾%s¡¿-",j&&(pat[crus][j]==pat[crus][j-1])?"Í£Áô":rms[pat[crus][j]].name.c_str());
        //			discov[crus][pat[crus][j]]=1;
        //		}
        //		printf("ËÀÍö\n\n");
        int lef = 0;
        for (int i = 1; i <= TAGS[crus + N]; i++) {
            if (tags[crus + N][i].msg == "ÊÖÇ¹" || tags[crus + N][i].msg == "Ê®×Ö")
                tags[crus + N][++lef] = tags[crus + N][i];
            else
                tags[pos[crus]][++TAGS[pos[crus]]] = tags[crus + N][i];
        }
        TAGS[crus + N] = lef;
        dead[crus] = ROUND + 1;
        NCPL = 0;
    }
}
void cubeturn()
{
    dor[6][20] = CUBETURN, dor[20][37] = CUBETURN, dor[6][37] = CUBETURN;
    dor[12][28] = CUBETURN, dor[28][46] = CUBETURN, dor[12][46] = CUBETURN;
    dor[20][6] = CUBETURN, dor[37][20] = CUBETURN, dor[37][6] = CUBETURN;
    dor[28][12] = CUBETURN, dor[46][28] = CUBETURN, dor[46][12] = CUBETURN;
    dor[13][22] = CUBETURN, dor[30][39] = CUBETURN, dor[24][32] = CUBETURN;
    dor[22][13] = CUBETURN, dor[39][30] = CUBETURN, dor[32][24] = CUBETURN;
    dor[9][22] = !CUBETURN, dor[30][31] = !CUBETURN;
    dor[22][9] = !CUBETURN, dor[31][30] = !CUBETURN;
    for (int i = 14; i <= 18; i++) {
        swap(rms[i].x, rms[36 - i].x);
        swap(rms[i].y, rms[36 - i].y);
    }
    for (int i = 23; i <= 26; i++) {
        swap(rms[i].x, rms[53 - i].x);
        swap(rms[i].y, rms[53 - i].y);
    }
    CUBETURN = !CUBETURN;
}
void route(int sx, int sy, int tx, int ty)
{
    if (sx > tx)
        swap(sx, tx), swap(sy, ty);
    if (abs(tx - sx) + abs(ty - sy) <= 230)
        ege_line(sx, sy, tx, ty);
    else {
        int midx = (sx + tx) / 2 - (ty - sy) / 2 * sqrt(3), midy = (sy + ty) / 2 + (tx - sx) / 2 * sqrt(3), cr = sqrt((tx - sx) * (tx - sx) + (ty - sy) * (ty - sy));
        //		ege_line(midx,midy,sx,sy);ege_line(midx,midy,tx,ty);ege_line(tx,ty,sx,sy);
        ege_arc(midx - cr, midy - cr, cr * 2, cr * 2, atan2(ty - midy, tx - midx) / pi * 180, -60);
    }
}
void setpos(int pid, int rep)
{
    pos[pid] = rep;
    psiz[pid] = 0;
    pat[pid][0] = rep;
}
void setpos2(int pid, int rep)
{
    pos[pid] = rep;
    int ct = psiz[pid];
    while (pat[pid][ct] > N)
        ct--;
    pat[pid][ct] = rep;
    printf("%d %d %d\n", pid, rep, ct);
}
void excroom(int i, int desed)
{
    swap(rms[i].name, rms[desed].name);
    swap(tags[i], tags[desed]);
    swap(TAGS[i], TAGS[desed]);
    swap(orirm[i], orirm[desed]);
    transed[orirm[i]] = i;
    transed[orirm[desed]] = desed;
    for (int j = 1; j <= PLS; j++) {
        if (pos[j] == desed)
            setpos2(j, i);
        else if (pos[j] == i)
            setpos2(j, desed);
    }
}
void systemreset(int round)
{
    printf("SYSTEMRESET\n");
    if (CUBETURN)
        cubeturn();
    for (int i = 1; i <= N; i++) {
        int desed = rand() % i + 1;
        excroom(i, desed);
    }
    for (int i = 1; i <= N; i++)
        transed[orirm[i]] = i;
    for (int i = 1; i <= PLS; i++)
        for (int j = 1; j <= N; j++)
            discov[i][j] = 0;
    for (int i = 1; i <= PLS; i++) {
        for (int j = 1; j <= round * 2; j++) {
            int h = rand() % N + 1;
            while (discov[i][h])
                h %= N, h++;
            discov[i][h] = 1;
        }
    }
    for (int i = 1; i <= N + PLS; i++) {
        for (int j = 1; j <= TAGS[i]; j++) {
            int has = hashx(tags[i][j].msg.c_str());
            if (has != hashx("¿ªËø") && has != hashx("ÊÖÇ¹") && has != hashx("×êÊ¯") && has != hashx("Ê®×Ö") && has != hashx("¼¯ÓÊ")) {
                for (int h = j + 1; h <= TAGS[i]; h++) {
                    tags[i][h - 1] = tags[i][h];
                }
                TAGS[i]--;
                j--;
            }
        }
    }
    freopen("n2.txt", "r", stdin);
    scanf("%*d");
    int plspls;
    scanf("%d", &plspls);
    for (int i = 1; i <= plspls; i++) {
        scanf("%*s");
    }
    scanf("%*d%*d");
    for (int i = 1; i <= N; i++) {
        scanf("%*s");
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dor[i][j] = 0;
    for (int i = 1; i <= M; i++) {
        int in1, in2;
        scanf("%d%d", &in1, &in2);
        dor[in1][in2] = dor[in2][in1] = 1;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%*d%*d%*d%*d");
    }
    int intags;
    scanf("%d", &intags);
    for (int i = 1; i <= intags; i++) {
        int aa, bb;
        string ss;
        scanf("%d%d%s", &aa, &bb, ss.c_str());
        if (hashx(ss.c_str()) == hashx("Ê®×Ö"))
            continue;
        tags[transed[aa]][++TAGS[transed[aa]]] = { bb, ss };
        printf("%s\n", ss.c_str());
    }
    scanf("%*d");
    fclose(stdin);
}
void expot()
{
    freopen("tags.txt", "w", stdout);
    int totag = 0;
    for (int i = 1; i <= N + PLS; i++) {
        totag += TAGS[i];
    }
    printf("%d\n", totag);
    for (int i = 1; i <= N + PLS; i++) {
        for (int j = 1; j <= TAGS[i]; j++)
            printf("%lld %lld %s\n", i, tags[i][j].type, tags[i][j].msg.c_str());
    }
    fclose(stdout);
    freopen("CON", "w", stdout);
}
void game(int pid)
{
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setbkmode(TRANSPARENT);
    ege_enable_aa(true);
    setbkcolor(0xff000000);
    setfont(-40, 0, "Î¢ÈíÑÅºÚ");
    setcolor(hsv2rgb(30, 1, 1));
    outtextxy(100, 50, name[pid].c_str());
    setcolor(hsv2rgb(1, 0, 1));
    setlinewidth(2);
    setfont(-16, 0, "Î¢ÈíÑÅºÚ");
    if (db(650, 50, 50, 30, "Ôö¼Ó", hsv2rgb(30, 1, 1))) {
        STP++;
        FS = 0;
    }
    if (db(720, 50, 50, 30, "¼õÉÙ", hsv2rgb(30, 1, 1))) {
        STP--;
        FS = 0;
    }
    setfont(-40, 0, "Î¢ÈíÑÅºÚ");
    int stpp = STP - psiz[pid];
    if (ROUND < 0) {
        if (STP == 1) {
            setcolor(hsv2rgb(0, 1, 1));
            outtextxy(260, 50, "½ô¼±±ÜÏÕ");
            setfont(-16, 0, "Î¢ÈíÑÅºÚ");
        }
        if (STP == 0) {
            setcolor(hsv2rgb(1, 0, 1));
            outtextxy(260, 50, "³õÊ¼Î»ÖÃ");
            setfont(-16, 0, "Î¢ÈíÑÅºÚ");
        }
    } else {
        setcolor(hsv2rgb(1, 0, 1));
        outtextxy(380, 50, "µÄ»ØºÏ »¹ÄÜÒÆ¶¯        ²½");
        setfont(-16, 0, "Î¢ÈíÑÅºÚ");
        setcolor(hsv2rgb(30, 1, 1));
        setfont(-70, 0, "Î¢ÈíÑÅºÚ");
        outtextxy(500, 50, n2s(stpp).c_str());
    }
    flag1 = 1, flag2 = 1;
    if (FS == 0) {
        bfs(pos[pid], stpp);
        for (int i = 1; i <= N; i++)
            sta[i] = 0;
        for (int i = 0; i <= psiz[pid]; i++) {
            if (pat[pid][i] < 10000)
                sta[pat[pid][i]] = -i - 1;
        }
        nstp = 0;
        FS = 1;
        STGO = 0;
    }
    setfont(-16, 0, "Î¢ÈíÑÅºÚ");
    setlinewidth(5);
    int rep = 0;
    for (int i = N; i >= 1; i--) {
        int flag = 0;
        if (sta[i] < 0) {
            flag = db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0xffffff, 0xff000000 | hsv2rgb(20, 1, 1 - (double)(psiz[pid] + sta[i] + 1) / (psiz[pid] + 1)), 0xffffffff);
        } else if (!discov[pid][i]) {
            setfont(-50, 0, "Î¢ÈíÑÅºÚ");
            flag = db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, n2s(i), 0xffffff, 0xff000000 | hsv2rgb(0, 0, 0.5 - (double)dis[i] * dis[i] / (stpp + 1) / (stpp + 1) / 2), 0xaaaaaa);
            setfont(-16, 0, "Î¢ÈíÑÅºÚ");
            //			setlinewidth(5);
            //			setcolor(0xff999999);
            //			ege_line(rms[i].x-rms[i].w/2+60,rms[i].y-rms[i].h/2+60,rms[i].x+rms[i].w/2+60,rms[i].y+rms[i].h/2+60);
            //			ege_line(rms[i].x+rms[i].w/2+60,rms[i].y-rms[i].h/2+60,rms[i].x-rms[i].w/2+60,rms[i].y+rms[i].h/2+60);
        } else if (sta[i] == 0) {
            flag = db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0xffffff, 0xff000000 | hsv2rgb(130 - flag1 * 80 + flag2 * 140, 1, 1 - (double)dis[i] * dis[i] / (stpp + 1) / (stpp + 1)));
        }
        if (flag == 1) {
            rep = i;
        }
    }
    if (STGO) {
        if (rep != 0) {
            pos[pid] = rep;
            psiz[pid] = 0;
            pat[pid][0] = rep;
            STGO = 0, FS = 0;
        }
        return;
    }
    for (int i = 1; i <= N; i++)
        if (sta[i] >= 1.0)
            sta[i] = 0;
    setlinewidth(25);
    setcolor(0x40000000 | hsv2rgb(1, 0, 1));
    if (LINE) {
        for (int i = 1; i <= N; i++) {
            if (dis[i] == stpp + 1)
                continue;
            for (int j = i + 1; j <= N; j++) {
                if (dis[j] == stpp + 1)
                    continue;
                if (dor[i][j] == 1) {
                    route(rms[i].x + 60, rms[i].y + 60, rms[j].x + 60, rms[j].y + 60);
                }
            }
        }
    }
    if (ROUND < 0) {
        string nstr;
        for (int i = 1; i <= PLS; i++) {
            if (pos[i] == pos[pid] && i != pid)
                nstr += "¡¾" + (string)name[i].c_str() + "¡¿";
        }
        if (nstr.size()) {
            setfillcolor(hsv2rgb(320, 1, 1) | 0xff000000);
            ege_fillrect(0, 880, 1200, 60);
            setcolor(hsv2rgb(1, 0, 1));
            setfont(-30, 0, "Î¢ÈíÑÅºÚ");
            outtextxy(600, 910, (string("ÌáÊ¾£ºÄãºÍ") + nstr + "ÔÚÍ¬Ò»¸ö·¿¼ä£¡").c_str());
        }
    } else {
        setfont(-40, 0, "Î¢ÈíÑÅºÚ");
        setcolor(hsv2rgb(1, 0, 1));
        outtextxy(240, 910, "ÏÖÔÚÊÇµÚ        »ØºÏ");
        setcolor(hsv2rgb(15, 1, 1));
        setlinewidth(2);
        setfont(-70, 0, "Î¢ÈíÑÅºÚ");
        outtextxy(280, 910, n2s(ROUND).c_str());
    }
    setfont(-16, 0, "Î¢ÈíÑÅºÚ");
    setlinewidth(2);
    if (pid < PLS && db(1125, 50, 50, 30, "·µ»Ø", hsv2rgb(190, 1, 1))) {
        int nrmnrm = NRM;
        NRM--;
        while (NRM && dead[NRM])
            NRM--;
        if (NRM == 0)
            NRM = nrmnrm;
        FS = 0;
    }
    if (db(800, 50, 50, 30, "Í¨Â·", hsv2rgb(190, 1, 1))) {
        LINE = !LINE;
    }
    if (db(900, 50, 50, 30, "ÒÆÎ»", hsv2rgb(280, 1, 1))) {
        STGO = 1;
        for (int i = 1; i <= N; i++)
            sta[i] = 0, dis[i] = 0;
    }
    int nrm = NRM;
    nrm++;
    while (dead[nrm])
        nrm++;
    if (db(1000, 50, 50, 30, "¹Ø±Õ", hsv2rgb(100, 1, 1))) {
        NRM = -1;
        FS = 0;
    }
    if (db(1075 + (pid == PLS) * 25, 50, 50, 30, "¼ÌÐø", hsv2rgb(190, 1, 1))) {
        NRM++;
        while (dead[NRM])
            NRM++;
        if (NRM >= PLS)
            NRM = -1;
        FS = 0;
    }
}
void poisonclr()
{
    for (int i = 1; i <= N; i++)
        poison[i] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= TAGS[i]; j++) {
            if (tags[i][j].msg == "¶¾Æø")
                poison[i] = 2;
        }
        if (poison[i] == 2) {
            for (int j = 1; j <= N; j++)
                if (dor[i][j])
                    poison[j] = max(poison[j], 1);
        }
    }
}
void actgm()
{
    printf("ACTGM\n");
    if (gms[1].pl) {
        systemreset(ROUND);
        for (int i = 1; i <= GMS; i++)
            gms[i].pl = 0;
        return;
    }
    if (gms[2].pl) {
        cubeturn();
        gms[2].pl = 0;
    }
    if (gms[3].pl) {
        dor[9][10] ^= 1;
        dor[10][9] ^= 1;
        gms[3].pl = 0;
    }
    if (gms[4].pl) {
        dor[transed[35]][transed[11]] ^= 1;
        dor[transed[11]][transed[35]] ^= 1;
        gms[4].pl = 0;
    }
    if (gms[5].pl) {
        int gys = transed[1];
        for (int i = 1; i <= TAGS[gys]; i++) {
            if (tags[gys][i].msg[0] == "Ã»µç"[0]) {
                tags[gys][i] = { 2, "ÓÐµç" };
            } else if (tags[gys][i].msg[0] == "ÓÐµç"[0]) {
                tags[gys][i] = { 3, "Ã»µç" };
            }
        }
        gms[5].pl = 0;
    }
    if (gms[6].pl) {
        gms[6].pl = 0;
    }
}
void act4b()
{
    int flag = 0;
    for (int i = 1; i <= PLS; i++)
        discov[i][transed[24]] = 0;
    for (int i = 1; i <= TAGS[transed[24]]; i++) {
        if (hashx(tags[transed[24]][i].msg.c_str()) == hashx("ºÚ°µ")) {
            flag = 1;
            break;
        }
    }
    printf("ACT %d\n", transed[24]);
    if (!flag)
        return;
    int tagt = rand() % N + 1;
    while (1) {
        int fla = 0;
        for (int i = 1; i <= PLS; i++)
            if (!dead[i] && discov[i][tagt]) {
                fla = 1;
                break;
            }
        if (fla == 0)
            break;
        tagt++;
        if (tagt > N)
            tagt = 1;
    }
    printf("%d %d\n", transed[24], tagt);
    excroom(transed[24], tagt);
}
void consle()
{
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setbkmode(TRANSPARENT);
    ege_enable_aa(true);
    setbkcolor(0xff000000);
    setfont(-40, 0, "Î¢ÈíÑÅºÚ");
    if (ROUND >= 0) {
        setcolor(hsv2rgb(27 * ROUND, 0.5, 1));
        outtextxy(350, 50, "µÚ    »ØºÏÖ÷³ÖÅÐ¶¨Ê±¼ä");
        setfont(-40, 0, "Î¢ÈíÑÅºÚ");
        outtextxy(210, 50, n2s(ROUND).c_str());
    }
    if (ROUND == -1) {
        setcolor(hsv2rgb(27 * ROUND, 0.5, 1));
        outtextxy(350, 50, "Çë¼ÌÐø");
        stp[0] = 2;
        stp[1] = 3;
    }
    if (ROUND == -2) {
        setcolor(hsv2rgb(27 * ROUND, 0.5, 1));
        outtextxy(350, 50, "ÓÎÏ·¿ªÊ¼×´Ì¬");
    }
    setcolor(hsv2rgb(30, 1, 1));
    setlinewidth(5);
    if (FS == 0) {
        /*		for(int i=1;i<=PLS;i++){
                                psiz[i]=0;
                                pat[i][0]=pos[i];
                        }*/
        LINE = 0;
        poisonclr();
        FS = 1;
    }
    for (int i = 1; i <= PLS; i++) {
        int ct = psiz[i];
        while (pat[i][ct] > N)
            ct--;
        pos[i] = pat[i][ct];
    }
    for (int i = 1; i <= N; i++)
        rmcnt[i] = 0;
    for (int i = 1; i <= PLS; i++) {
        if (dead[i] && dead[i] <= ROUND)
            continue;
        for (int j = 0; j <= psiz[i]; j++) {
            int ct = j;
            while (pat[i][ct] > N)
                ct--;
            offst[i][j] = ++rmcnt[pat[i][ct]];
        }
    }
    for (int i = 1; i <= PLS; i++) {
        for (int j = 0; j <= psiz[i]; j++) {
            int ct = j;
            while (pat[i][ct] > N)
                ct--;
            offst[i][j] = 80.0 * offst[i][j] / (rmcnt[pat[i][ct]] + 1) - 40.0;
        }
    }
    setfont(-40, 0, "Î¢ÈíÑÅºÚ");
    setlinewidth(5);
    if (!MODF)
        for (int i = 1; i <= PLS; i++) {
            if (dead[i]) {
                if (db(100 + (i - 1) * 1000 / (PLS - 1), 910, 90, 60, name[i], 0xff000000, 0, hsv2rgb(360.0 * i / PLS, 1, 0.3)))
                    dead[i] = 0;
                setcolor(0xff000000 | hsv2rgb(360.0 * i / PLS, 1, 1));
                route(100 + (i - 1) * 1000 / (PLS - 1) - 45, 880, 100 + (i - 1) * 1000 / (PLS - 1) + 45, 940);
                route(100 + (i - 1) * 1000 / (PLS - 1) + 45, 880, 100 + (i - 1) * 1000 / (PLS - 1) - 45, 940);
            } else if (db(100 + (i - 1) * 1000 / (PLS - 1), 910, 90, 60, name[i], 0xff000000, 0, hsv2rgb(360.0 * i / PLS, 1, 1 - (psiz[i] >= stp[i == PLS]) * 0.7 * !!stp[i == PLS])))
                i == NCPL ? (NCPL = 0, STLV = STRM = 0) : (NCPL = i, STLV = 100, STRM = pos[i]);
        }
    setfont(-16, 0, "Î¢ÈíÑÅºÚ");
    if (!MODF)
        for (int i = N; i >= 1; i--) {
            if (discov[NCPL][i] == 1)
                db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, "", 0, 0xff000000 | hsv2rgb(360.0 * NCPL / PLS, 1, 0.3));
            db(rms[i].x + 20, rms[i].y + 20, rms[i].w, rms[i].h, n2s(i), 0xff000000, 0, 0x04c9ff);
            if (poison[i] == 2)
                db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0x888888, 0xff000000 | hsv2rgb(120, 1, sin(ani * 3) / 15 + 0.6));
            else if (poison[i] == 1)
                db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0x888888, 0xff000000 | hsv2rgb(120, 1, 0.2));
            else
                db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0x888888, 0);
        }
    else {
        if (MODF == 1) {
            if (NCPL) {
                for (int i = N; i >= 1; i--) {
                    if (db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0xffffff, 0xff000000 | hsv2rgb(360.0 * NCPL / PLS, 1, 0.8 - discov[NCPL][i] * 0.5))) {
                        discov[NCPL][i] ^= 1;
                        pat[NCPL][++psiz[NCPL]] = 20000 + i;
                        MODF = 0;
                        break;
                    };
                    db(rms[i].x + 20, rms[i].y + 20, rms[i].w, rms[i].h, n2s(i), 0xff000000, 0, 0xffffff);
                }
                return;
            } else {
                int rep = 0;
                for (int i = N; i >= 1; i--) {
                    if (db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0xffffff, 0xff000000 | hsv2rgb(300, 1, 1 - (i == mdtag1) * 0.5)))
                        rep = i;
                    db(rms[i].x + 20, rms[i].y + 20, rms[i].w, rms[i].h, n2s(i), 0xff000000, 0, 0xffffff);
                }
                if (rep > 0) {
                    if (mdtag1 == 0) {
                        mdtag1 = rep;
                    } else if (mdtag1 == rep) {
                        mdtag1 = 0;
                    } else {
                        dor[mdtag1][rep] = !dor[mdtag1][rep];
                        dor[rep][mdtag1] = !dor[rep][mdtag1];
                        mdtag1 = 0;
                        MODF = 0;
                    }
                }
            }
        } else {
            if (NCPL) {
                for (int i = N; i >= 1; i--) {
                    if (db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0xffffff, 0xff000000 | hsv2rgb(360.0 * NCPL / PLS, 1, 0.2))) {
                        pat[NCPL][++psiz[NCPL]] = i;
                        MODF = 0;
                        break;
                    };
                    db(rms[i].x + 20, rms[i].y + 20, rms[i].w, rms[i].h, n2s(i), 0xff000000, 0, 0xffffff);
                }
                return;
            } else {
                int rep = 0;
                for (int i = N; i >= 1; i--) {
                    if (db(rms[i].x + 60, rms[i].y + 60, rms[i].w, rms[i].h, rms[i].name, 0xffffff, 0xff000000 | hsv2rgb(30, 1, 1 - (i == mdtag1) * 0.5)))
                        rep = i;
                    db(rms[i].x + 20, rms[i].y + 20, rms[i].w, rms[i].h, n2s(i), 0xff000000, 0, 0xffffff);
                }
                if (rep > 0) {
                    if (mdtag1 == 0) {
                        mdtag1 = rep;
                    } else if (mdtag1 == rep) {
                        mdtag1 = 0;
                    } else {
                        excroom(mdtag1, rep);
                        mdtag1 = 0;
                        MODF = 0;
                    }
                }
            }
        }
    }
    if (MODF)
        return;
    for (int i = 1; i <= PLS; i++) {
        if (dead[i])
            continue;
        setcolor(0xff000000 | hsv2rgb(360.0 * i / PLS, 1, 1));
        if (i != NCPL)
            ege_ellipse(POSPx(i) - 20, POSPy(i) - 20, 40, 40);
    }
    if (NCPL) {
        setlinewidth(5);
        setcolor(0xff000000 | hsv2rgb(360.0 * NCPL / PLS, 1, 1));
        ege_line(100 + (NCPL - 1) * 1000 / (PLS - 1), 880, POSPx(NCPL), POSPy(NCPL));
        ege_line(POSPx(NCPL) - 20, POSPy(NCPL) - 20, POSPx(NCPL) + 20, POSPy(NCPL) + 20);
        ege_line(POSPx(NCPL) - 20, POSPy(NCPL) + 20, POSPx(NCPL) + 20, POSPy(NCPL) - 20);
        if (db(POSPx(NCPL), POSPy(NCPL), 40, 40, " ", 0xff000000, 0, 0)) {
            kp(NCPL);
            return;
        };
        for (int i = 1; i <= N; i++) {
            setcolor(0xff000000 | hsv2rgb(360.0 * NCPL / PLS, 1, 1));
            if (dor[i][pos[NCPL]] == 1) {
                int ful = (psiz[NCPL] >= stp[NCPL == PLS]);
                setlinewidth(5 - ful * 2);
                ege_ellipse(rms[i].x + 40 + ful * 5, rms[i].y + 40 + ful * 5, 40 - ful * 10, 40 - ful * 10);
                setfont(-30 + ful * 10, 0, "Î¢ÈíÑÅºÚ");
                char css[5] = "0";
                css[0] += max(-psiz[NCPL] + stp[NCPL == PLS], 0);
                setcolor(hsv2rgb(360.0 * NCPL / PLS, 1, 1));
                outtextxy(rms[i].x + 60, rms[i].y + 60, css);
                setcolor(0xff000000 | hsv2rgb(360.0 * NCPL / PLS, 1, 1));
                setfont(-16, 0, "Î¢ÈíÑÅºÚ");
                if (db(rms[i].x + 60, rms[i].y + 60, 40, 40, " ", 0xff000000, 0, 0))
                    pat[NCPL][++psiz[NCPL]] = i, STLV = 100, STRM = i;
            }
        }
        setfont(-16, 0, "Î¢ÈíÑÅºÚ");
        setlinewidth(2);
        if (psiz[NCPL] && db(680, 50, 50, 30, "ºóÍË", hsv2rgb(360.0 * NCPL / PLS, 1, 1))) {
            if (pat[NCPL][psiz[NCPL]] > 10000 && pat[NCPL][psiz[NCPL]] < 20000)
                gms[pat[NCPL][psiz[NCPL]] - 10000].pl = 0;
            if (pat[NCPL][psiz[NCPL]] > 20000)
                discov[NCPL][pat[NCPL][psiz[NCPL]] - 20000] ^= 1;
            psiz[NCPL]--;
            int ct = psiz[NCPL];
            while (ct > N)
                ct--;
            STLV = 100, STRM = pat[NCPL][ct];
        }
        if (psiz[NCPL] < stp[NCPL == PLS] && db(730, 50, 50, 30, "Í£Áô", hsv2rgb(360.0 * NCPL / PLS, 1, 1))) {
            pat[NCPL][psiz[NCPL] + 1] = 10000;
            psiz[NCPL]++;
        }
        if (db(95, 50, 50, 30, "Ì½Ë÷", hsv2rgb(360.0 * NCPL / PLS, 1, 1))) {
            MODF = 1;
        }
        if (db(45, 50, 50, 30, "ÒÆÎ»", hsv2rgb(360.0 * NCPL / PLS, 1, 1))) {
            MODF = 2;
        }
        if (db(610, 50, 90, 30, "²é¿´µØÍ¼", hsv2rgb(360.0 * NCPL / PLS, 1, 1))) {
            NRM = NCPL;
            STRM = 0;
            //			NCPL=0;
            FS = 0;
            LINE = 1;
            return;
        }
    } else {
        setlinewidth(2);
        if (db(600, 50, 50, 30, "±£´æ", hsv2rgb(0, 1, 1))) {
            char s[590];
            inputbox_getline("±£´æ", "ÊäÈë´æµµÃû£¨²»¼Ó.txtºó×º£©", s, 416);
            save(s);
        }
        if (db(650, 50, 50, 30, "¶ÁÈ¡", hsv2rgb(0, 1, 1))) {
            char s[590];
            inputbox_getline("¶ÁÈ¡", "ÊäÈë´æµµÃû£¨²»¼Ó.txtºó×º£©", s, 416);
            load(s);
            return;
        }
        if (db(725, 50, 50, 30, "½»»»", hsv2rgb(30, 1, 1))) {
            MODF = 2;
            NCPL = 0;
            return;
        }
    }
    if (STLV <= 0.1)
        STLV = 0;
    for (int i = 1; i <= PLS; i++) {
        setlinewidth(5);
        setcolor(0xff000000 | hsv2rgb(360.0 * i / PLS, 1, 1 - 0.2 * !!dead[i]));
        setfillcolor(0xff000000 | hsv2rgb(360.0 * i / PLS, 1, 1 - 0.2 * !!dead[i]));
        if (dead[i] && dead[i] <= ROUND)
            continue;
        else if (dead[i]) {
            ege_line(POSPx(i) - 20, POSPy(i) - 20, POSPx(i) + 20, POSPy(i) + 20);
            ege_line(POSPx(i) - 20, POSPy(i) + 20, POSPx(i) + 20, POSPy(i) - 20);
        }
        for (int j = 0; j < psiz[i]; j++) {
            int tst = j, ttt = j + 1;
            while (pat[i][tst] > N)
                tst--;
            while (pat[i][ttt] > N)
                ttt--;
            if (pat[i][tst] == pat[i][ttt]) {
                int x0x = rms[pat[i][tst]].x + 60 + offst[i][j], y0y = rms[pat[i][tst]].y + 60 + offst[i][j];
                ege_fillellipse(x0x - 10, y0y - 10, 20, 20);
                if (pat[i][j + 1] > 20000) {
                    setlinewidth(3);
                    room& pp = rms[pat[i][j + 1] - 20000];
                    ege_line(x0x, y0y, pp.x, pp.y);
                    ege_line(x0x, y0y, pp.x + pp.w, pp.y);
                    ege_line(x0x, y0y, pp.x, pp.y + pp.h);
                    ege_line(x0x, y0y, pp.x + pp.w, pp.y + pp.h);
                    setlinewidth(5);
                }
            } else
                route(rms[pat[i][tst]].x + 60 + offst[i][j], rms[pat[i][tst]].y + 60 + offst[i][j], rms[pat[i][ttt]].x + 60 + offst[i][j + 1], rms[pat[i][ttt]].y + 60 + offst[i][j + 1]);
        }
    }
    setlinewidth(25);
    if (LINE) {
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                setcolor(0x60000000 | hsv2rgb(NCPL ? 360.0 * NCPL / PLS : 1, i == pos[NCPL] || j == pos[NCPL], 1));
                if (dor[i][j] == 1) {
                    route(rms[i].x + 60, rms[i].y + 60, rms[j].x + 60, rms[j].y + 60);
                }
            }
        }
    }
    setfont(-16, 0, "Î¢ÈíÑÅºÚ");
    setlinewidth(2);
    //	if(db(720,150,50,30,"£¿£¿",hsv2rgb(190+READYRESET*180,1,1))){
    //		READYRESET^=1;
    //	}
    if (db(900, 50, 90, 30, "Ðý×ªÄ§·½", hsv2rgb(190, 1, 1))) {
        cubeturn();
    }
    setlinewidth(2);
    if (db(800, 50, 50, 30, "Í¨Â·", hsv2rgb(190, 1, 1))) {
        LINE = !LINE;
    }
    if (db(1000, 50, 50, 30, "¸Ä½¨", hsv2rgb(300, 1, 1))) {
        MODF = 1;
        NCPL = 0;
    }
    if (db(1100, 50, 50, 30, "Íê³É", hsv2rgb(320, 1, 1))) {
        if (ROUND >= 0)
            save("R" + n2s(ROUND));
        else if (ROUND == -2)
            save("S");
        if (ROUND == -2)
            saveimage(DESK, "screenshots\\S.jpg");
        if (ROUND >= 0)
            saveimage(DESK, ("screenshots\\R" + n2s(ROUND) + ".jpg").c_str());
        STRM = 0;
        NCPL = 0;
        FS = 0;
        LINE = 1;
        for (int i = 1; i <= PLS; i++) {
            printf("%d BEGAN\n", i);
            //			if(NRM==-1&&i==PLS)continue;
            //			if(NRM==-2&&i!=PLS)continue;
            if (dead[i])
                continue;
            //			printf("¡¾%s¡¿¶¯Ïò£º\n",name[i].c_str());
            for (int j = 0; j <= psiz[i]; j++) {
                //				printf("¡¾%s¡¿",j&&(pat[i][j]==pat[i][j-1])?"Í£Áô":rms[pat[i][j]].name.c_str());
                //				printf("%c",j==psiz[i]?'\n':'-');
                if (pat[i][j] <= N)
                    discov[i][pat[i][j]] = 1;
            }
            //			printf("\n");
            psiz[i] = 0;
            pat[i][0] = pos[i];
        }
        if (dead[PLS]) {
            dead[PLS] = 0;
            pos[PLS] = transed[14];
            psiz[PLS] = 0;
            pat[PLS][0] = pos[PLS];
        }
        act4b();
        actgm();
        if (ROUND % 2)
            NRM = PLS;
        else
            NRM = 1;
        ROUND++;
    }
}
void imp()
{
    freopen("n2.txt", "r", stdin);
    int seed;
    scanf("%d", &seed);
    srand(seed);
    scanf("%d", &PLS);
    for (int i = 1; i <= PLS; i++) {
        scanf("%s", name[i].c_str());
        //		cout<<name[i]<<endl;
    }
    scanf("%d%d", &N, &M);
    //	cout<<N<<M<<endl;
    for (int i = 1; i <= N; i++) {
        scanf("%s", rms[i].name.c_str());
    }
    random_shuffle(name + 1, name + PLS + 1);
    printf("Íæ¼ÒË³Ðò£º\n\n");
    for (int i = 1; i <= PLS; i++)
        printf("%s\n", name[i].c_str());
    printf("\n");
    for (int i = 1; i <= M; i++) {
        int in1, in2;
        scanf("%d%d", &in1, &in2);
        dor[in1][in2] = dor[in2][in1] = 1;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d%d", &rms[i].x, &rms[i].y, &rms[i].w, &rms[i].h);
    }
    for (int i = 1; i <= PLS; i++) {
        pos[i] = rand() % N + 1ll;
        discov[i][pos[i]] = 1;
        pat[i].resize(499);
        psiz[i] = 0;
        pat[i][0] = pos[i];
    }
    stp[0] = 0;
    stp[1] = 0;
    int intags;
    scanf("%d", &intags);
    for (int i = 1; i <= intags; i++) {
        int aa, bb;
        string ss;
        scanf("%d%d%s", &aa, &bb, ss.c_str());
        tags[aa][++TAGS[aa]] = { bb, ss };
    }
    scanf("%d", &NHB);
    fclose(stdin);
}
void gminit()
{
    GMS = 6;
    gms[1] = { 44, 0, 0, 0, "ÖØÆô" };
    gms[2] = { 18, 0, 0, 0, "Ä§·½" };
    gms[3] = { 33, 0, 0, 0, "ÆË¿Ë" };
    gms[4] = { 35, 0, 0, 0, "¾õÐÑ" };
    gms[5] = { 29, 0, 0, 0, "µçÃÅ" };
    gms[6] = { 3, 0, 0, 0, "±ÚÂ¯" };
}
void drawgm()
{
    for (int i = 1; i <= N; i++)
        rmgm[i] = 0;
    for (int i = 1; i <= GMS; i++) {
        if (NRM > 0 && !discov[NRM][transed[gms[i].rom]])
            continue;
        rmgm[transed[gms[i].rom]]++;
        int curx = 50, cury = 0, cpos = transed[gms[i].rom], bx = rms[cpos].x + 60, by = rms[cpos].y + 60;
        double tx = curx, ty = cury, tc = 2.0 * pi / (rmgm[cpos] + TAGS[cpos]) + ani;
        curx = tx * cos(tc) - ty * sin(tc);
        cury = tx * sin(tc) + ty * cos(tc);
        int nea = ((msg.x - bx - curx) * (msg.x - bx - curx) + (msg.y - by - cury) * (msg.y - by - cury) < 400);
        ege_point hex[7];
        hex[0] = { 24 * cos(tc / pi), 24 * sin(tc / pi) };
        for (int i = 1; i <= 5; i++) {
            float lx = hex[i - 1].x, ly = hex[i - 1].y;
            hex[i] = { lx * 0.5 - ly * sqrt(0.75), lx * sqrt(0.75) + ly * 0.5 };
        }
        for (int i = 0; i <= 6; i++) {
            hex[i].x += bx + curx;
            hex[i].y += by + cury;
        }
        hex[6] = hex[0];
        setfillcolor(0xff000000 | hsv2rgb(0, 0, nea / 3.0));
        setcolor(0xff000000 | hsv2rgb(200, 1, 1));
        setlinewidth(2);
        if (gms[i].pl) {
            int cpl = gms[i].pl, ccx = 0, ccy = 0;
            setcolor(0xff000000 | hsv2rgb(360.0 * cpl / PLS, 1, 1));
            setlinewidth(3);
            for (int j = 0; j <= psiz[cpl]; j++) {
                if (pat[cpl][j] == 10000 + i) {
                    int ct = j;
                    while (pat[cpl][ct] > N)
                        ct--;
                    ccx = rms[pat[cpl][ct]].x + 60 + offst[cpl][j], ccy = rms[pat[cpl][ct]].y + 60 + offst[cpl][j];
                    break;
                }
            }
            for (int i = 1; i <= 6; i++) {
                ege_line(hex[i].x, hex[i].y, ccx, ccy);
            }
        }
        ege_fillpoly(7, hex);
        ege_drawpoly(7, hex);
        setfont(-16, 0, "Î¢ÈíÑÅºÚ");
        if (!gms[i].pl)
            setcolor(hsv2rgb(200, 1, 1));
        else
            setcolor(hsv2rgb(360.0 * gms[i].pl / PLS, 1, 1));
        outtextxy(bx + curx, by + cury, gms[i].name.c_str());
        if (nea && msg.is_down() - lmsg.is_down() > 0) {
            if (gms[i].pl == 0) {
                if (NCPL) {
                    gms[i].pl = NCPL;
                    int des = 0;
                    for (des = 0; des <= psiz[NCPL]; des++) {
                        if (pat[NCPL][des] == transed[gms[i].rom]) {
                            des++;
                            break;
                        }
                    }
                    for (int j = psiz[NCPL]; j >= des; j--)
                        pat[NCPL][j + 1] = pat[NCPL][j];
                    pat[NCPL][des] = 10000 + i;
                    psiz[NCPL]++;
                    if (i == 4 || i == 1) {
                        kp(NCPL);
                        NCPL = 0;
                    }
                }
            } else {
                int des, ncpl = gms[i].pl;
                for (des = 0; des <= psiz[ncpl]; des++) {
                    if (pat[ncpl][des] == 10000 + i)
                        break;
                }
                for (int j = des + 1; j <= psiz[ncpl]; j++)
                    pat[ncpl][j - 1] = pat[ncpl][j];
                psiz[ncpl]--;
                gms[i].pl = 0;
            }
        }
    }
}
int cols[10] = { 0, 0, 60, 240, 120, 180, 300, 270, 30, 200 };
void addtag(int type)
{
    char mssg[500];
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        if (rms[i].x + 60 + rms[i].w / 2 >= msg.x && rms[i].x + 60 - rms[i].w / 2 <= msg.x && rms[i].y + 60 + rms[i].h / 2 >= msg.y && rms[i].y + 60 - rms[i].w / 2 <= msg.y)
            pos = i;
    }
    if (pos == 0) {
        for (int i = 1; i <= PLS; i++)
            if (100 + (i - 1) * 1000 / (PLS - 1) + 45 >= msg.x && 910 + 30 >= msg.y && 100 + (i - 1) * 1000 / (PLS - 1) - 45 <= msg.x && 910 - 30 <= msg.y)
                pos = i + N;
    }
    if (pos == 0)
        return;
    inputbox_getline("±êÇ©", "ÊäÈë±ê¼ÇÄÚÈÝ", mssg, 416);
    //	printf("a");
    //	printf("%lld",TAGS[pos]);
    tags[pos][++TAGS[pos]] = { type, mssg };
    poisonclr();
}
void drawmsg()
{
    for (int i = 1; i <= N + PLS; i++) {
        int dark = 0;
        for (int j = 1; j <= TAGS[i]; j++) {
            if (hashx(tags[i][j].msg) == hashx("ºÚ°µ"))
                dark = 1;
        }
        for (int j = 1; j <= TAGS[i]; j++) {
            //			if(tags[i][j].type<=7&&NRM>0&&NRM!=i-N)continue;
            int curx = 50, cury = 0, bx = rms[i].x + 60, by = rms[i].y + 60, isst = 0;
            if (i <= N) {
                if (NRM > 0 && !discov[NRM][i] && sta[i] >= 0)
                    continue;
                if (NRM > 0 && sta[i] >= 0 && tags[i][j].type <= 7)
                    continue;
                if (NRM > 0 && dark && hashx(tags[i][j].msg) != hashx("ºÚ°µ"))
                    continue;
                double tx = curx, ty = cury, tc = 2.0 * pi * (j + rmgm[i]) / (rmgm[i] + TAGS[i]) + ani;
                curx = tx * cos(tc) - ty * sin(tc);
                cury = tx * sin(tc) + ty * cos(tc);
                if (i == STRM)
                    isst = STLV + 10;
            } else if (NRM < 0) {
                cury = -30;
                curx = 100 * j / (TAGS[i] + 1) - 50, bx = 100 + (i - N - 1) * 1000 / (PLS - 1), by = 910;
                if (pos[i - N] == STRM)
                    isst = STLV + 10;
            } else if (NRM > 0 && NRM == i - N) {
                cury = 0;
                curx = 400 * j / (TAGS[i] + 1) - 200, bx = 600, by = 910;
            } else
                continue;
            int nea = ((msg.x - bx - curx) * (msg.x - bx - curx) + (msg.y - by - cury) * (msg.y - by - cury) < 400);
            if (nea && msg.is_down() - lmsg.is_down() > 0) {
                msg.x = -20;
                msg.y = -20;
                for (int h = j + 1; h <= TAGS[i]; h++) {
                    tags[i][h - 1] = tags[i][h];
                }
                TAGS[i]--;
                poisonclr();
                return;
            }
            setcolor(0xff000000 | hsv2rgb(cols[tags[i][j].type], 1, 1));
            setfillcolor(0xff000000 | hsv2rgb(0, 0, nea / 3.0));
            setlinewidth(2);
            ege_ellipse(bx + curx - 20 - isst, by + cury - 20 - isst, 40 + isst * 2, 40 + isst * 2);
            ege_fillellipse(bx + curx - 20 - isst, by + cury - 20 - isst, 40 + isst * 2, 40 + isst * 2);
            setcolor(hsv2rgb(cols[tags[i][j].type], 1, 1));
            setfont(-16, 0, "Î¢ÈíÑÅºÚ");
            outtextxy(bx + curx, by + cury, tags[i][j].msg.c_str());
        }
    }
}
void shuffle()
{
    int dtwz = 0;
    for (int i = 1; i <= N; i++) {
        int desed = rand() % i + 1;
        swap(rms[i].name, rms[desed].name);
        swap(tags[i], tags[desed]);
        swap(TAGS[i], TAGS[desed]);
        orirm[i] = orirm[desed];
        orirm[desed] = i;
    }
    for (int i = 1; i <= N; i++)
        transed[orirm[i]] = i;
    while (orirm[dtwz] != 7)
        dtwz++;
    bfs(dtwz, 3);
    printf("%d\n", transed[7]);
    for (int i = 1; i <= 3; i++) {
        int kpos = rand() % N + 1;
        while (dis[kpos] < 4)
            kpos = rand() % N + 1;
        tags[kpos][++TAGS[kpos]] = { 4, "¿ªËø" };
    }
    int kpos = 0;
    kpos = rand() % N + 1;
    tags[kpos][++TAGS[kpos]] = { 5, "¼¯ÓÊ" };
    printf("¡¾%s¡¿\n", rms[kpos].name.c_str());
    printf("\n");
    tags[N + PLS][++TAGS[N + PLS]] = { 1, "ÊÖÇ¹" };
}
void save(string sname)
{
    freopen(("saves\\" + sname + ".txt").c_str(), "w", stdout);
    //	TAGS[999],dor[999][999],stp[2],psiz[99],dead[999],discov[999][997],orirm[999],transed[999];vector<tag> tags[999];vector<int> pat[99];
    printf("%d\n", PLS);
    for (int i = 1; i <= PLS; i++) {
        printf("%s ", name[i].c_str());
    }
    printf("\n");
    printf("%d\n%d %d\n", ROUND, stp[0], stp[1]);
    for (int i = 1; i <= N + PLS; i++) {
        printf("%d ", TAGS[i]);
        for (int j = 1; j <= TAGS[i]; j++)
            printf("%d +%s ", tags[i][j].type, tags[i][j].msg.c_str());
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", dor[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= PLS; i++) {
        printf("%d %d ", dead[i], psiz[i]);
        for (int j = 0; j <= psiz[i]; j++)
            printf("%d ", pat[i][j]);
        printf("\n");
        for (int j = 1; j <= N; j++) {
            printf("%d ", discov[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= GMS; i++) {
        printf("%d ", gms[i].pl);
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        printf("%d ", orirm[i]);
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        printf("%d ", transed[i]);
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        printf("%s ", rms[i].name.c_str());
    }
    printf("\n");
    fclose(stdout);
    freopen("CON", "w", stdout);
}
void load(string sname)
{
    freopen(("saves\\" + sname + ".txt").c_str(), "r", stdin);
    //	TAGS[999],dor[999][999],stp[2],psiz[99],dead[999],discov[999][997],orirm[999],transed[999];vector<tag> tags[999];vector<int> pat[99];
    scanf("%d", &PLS);
    for (int i = 1; i <= PLS; i++) {
        char namme[190];
        scanf("%s", namme);
        name[i] = (string)namme;
        pat[i].resize(500);
    }
    scanf("%d%d%d", &ROUND, &stp[0], &stp[1]);
    for (int i = 1; i <= N + PLS; i++) {
        scanf("%d", &TAGS[i]);
        //		printf("%d %d\n",i,TAGS[i]);
        for (int j = 1; j <= TAGS[i]; j++) {
            int typ;
            char mssg[190] = "";
            scanf("%d%s", &typ, mssg);
            //			printf("%d %s ",typ,mssg);
            tags[i][j] = { typ, string(mssg + 1) };
        }
        //		printf("\n");
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &dor[i][j]);
        }
    }
    for (int i = 1; i <= PLS; i++) {
        scanf("%d%d", &dead[i], &psiz[i]);
        for (int j = 0; j <= psiz[i]; j++)
            scanf("%d ", &pat[i][j]);
        for (int j = 1; j <= N; j++) {
            scanf("%d ", &discov[i][j]);
        }
    }
    for (int i = 1; i <= GMS; i++) {
        scanf("%d", &gms[i].pl);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d ", &orirm[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d ", &transed[i]);
    }
    for (int i = 1; i <= N; i++) {
        char namme[450] = "";
        scanf("%s", namme);
        //		printf("%d %s\n",i,namme);
        rms[i].name = namme;
    }
    fclose(stdin);
}
int main()
{
    for (int i = 1; i <= 144; i++)
        tags[i].resize(60);
    imp();
    gminit();
    shuffle();
    setinitmode(0);
    initgraph(NHB, NHB * 4 / 5);
    setcaption("ºÚÓ°É±");
    setrendermode(RENDER_MANUAL);
    setbkcolor(0xffffff);
    ROOM = 0;
    DESK = newimage(1200, 960);
    OTTA = newimage(1200, 960);
    for (; is_run(); delay_fps(24)) {
        ani += 0.05;
        lmsg = msg;
        while (mousemsg()) {
            msg = getmouse();
            msg.x = (double)msg.x / NHB * 1200;
            msg.y = (double)msg.y / NHB * 1200;
        }
        //		printf("%d %d\n",msg.x,msg.y);
        if (kbmsg())
            ksg = getkey();
        switch (ROOM) {
        case 0: {
            settarget(DESK);
            cleardevice();
            title();
            break;
        }
        case 1: {
            if (ksg.key <= '9' && ksg.key >= '1') {
                addtag(ksg.key - 48);
                ksg.key = 0;
            }
            if (msg.is_down() - lmsg.is_down()) {
                settarget(OTTA);
                cleardevice();
                if (NRM > 0) {
                    while (dead[NRM])
                        NRM++;
                    game(NRM);
                } else
                    consle();
                settarget(DESK);
            }
            settarget(DESK);
            cleardevice();
            putimage(DESK, 0, 0, 1200, 1000, OTTA, 0, 0, 1200, 1000);
            drawgm();
            drawmsg();
            STLV *= 0.8;
            break;
        }
        }
        settarget(NULL);
        putimage_rotatezoom(NULL, DESK, 0, 0, 0, 0, 0, (double)NHB / 1200, 0, -1, 1);
    }
    closegraph();
    return 0;
}
