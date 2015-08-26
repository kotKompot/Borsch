#include "Dijkstra.h"


Node *inic( int start, int end, Node *mar[1000])
{



    int kx=0; //поправочные коэфиц для быстрого исправления,
    int ky=0; //если будет некорректно работать на мониторах с разным разрешением

    Node *s1 = new Node(95,"s1",1,1,155+kx,506+ky,mar);
    Node *ln1 = new Node(96,"ln1",1,1,129+kx,506+ky,mar);

    Node *ln2 = new Node(97,"ln2",1,1,484+kx,510+ky,mar);
    Node *ln4 = new Node(98,"ln3",1,1,881+kx,519+ky,mar);
    Node *ln5 = new Node(99,"ln5",1,1,1107+kx,528+ky,mar);
   Node *ln3   = new Node(100,"MainEnter",1,1,687+kx,510+ky,mar);


    Node *r101 = new Node(1,"101",1,1,135+kx,262+ky,mar);
    Node *r102 = new Node(2,"102",1,1,135+kx,263+ky,mar);
    Node *r103 = new Node(3,"103",1,1,135+kx,300+ky,mar);
    Node *r104 = new Node(4,"104",1,1,135+kx,301+ky,mar);
    Node *r106 = new Node(5,"106",1,1,135+kx,314+ky,mar);
    Node *r107 = new Node(6,"107",1,1,135+kx,372+ky,mar);
    Node *r108 = new Node(7,"108",1,1,135+kx,412+ky,mar);
    Node *r109 = new Node(8,"109",1,1,133+kx,425+ky,mar);
    Node *r110 = new Node(9,"110",1,1,133+kx,426+ky,mar);
    Node *r111 = new Node(10,"111",1,1,131+kx,460+ky,mar);
    Node *r112 = new Node(11,"112",1,1,129+kx,483+ky,mar);
    Node *r113 = new Node(12,"113",1,1,126+kx,522+ky,mar);
    Node *r114 = new Node(13,"114",1,1,126+kx,523+ky,mar);
    Node *r115 = new Node(14,"115",1,1,142+kx,521+ky,mar);
    Node *r116 = new Node(15,"116",1,1,173+kx,506+ky,mar);
    Node *r117 = new Node(16,"117",1,1,207+kx,507+ky,mar);
    Node *r117a = new Node(17,"117a",1,1,223+kx,508+ky,mar);
    Node *r118 = new Node(18,"118",1,1,242+kx,510+ky,mar);
    Node *r119 = new Node(19,"119",1,1,255+kx,510+ky,mar);
    Node *r121 = new Node(21,"121",1,1,256+kx,510+ky,mar);
    Node *r120 = new Node(20,"120",1,1,288+kx,510+ky,mar);
    Node *r122 = new Node(22,"122",1,1,304+kx,510+ky,mar);
    Node *r123 = new Node(23,"123",1,1,320+kx,510+ky,mar);
    Node *r124 = new Node(24,"124",1,1,322+kx,510+ky,mar);
    Node *r125 = new Node(25,"125",1,1,352+kx,510+ky,mar);
    Node *rMainAccounting = new Node(26,"MainAccounting",1,1,351+kx,510+ky,mar);
    Node *r126 = new Node(27,"126",1,1,370+kx,510+ky,mar);
    Node *r127 = new Node(28,"127",1,1,387+kx,510+ky,mar);
    Node *r128 = new Node(29,"128",1,1,426+kx,510+ky,mar);
    Node *r129 = new Node(30,"129",1,1,436+kx,510+ky,mar);
    Node *r130 = new Node(31,"130",1,1,467+kx,510+ky,mar);
    Node *r131 = new Node(32,"131",1,1,484+kx,356+ky,mar);

    Node *r132 = new Node(33,"132",1,1,484+kx,340+ky,mar);
    Node *r133 = new Node(34,"133",1,1,484+kx,296+ky,mar);
    Node *r134 = new Node(35,"134",1,1,484+kx,265+ky,mar);
    Node *r135 = new Node(36,"135",1,1,484+kx,224+ky,mar);
    Node *r135a = new Node(37,"135a",1,1,484+kx,240+ky,mar);
    Node *r136 = new Node(38,"136",1,1,484+kx,241+ky,mar);
    Node *r137 = new Node(39,"137",1,1,484+kx,298+ky,mar);
    Node *r138 = new Node(40,"138",1,1,484+kx,313+ky,mar);
    Node *r139 = new Node(41,"139",1,1,484+kx,338+ky,mar);
    Node *r140 = new Node(42,"140",1,1,484+kx,355+ky,mar);
    Node *r141 = new Node(43,"141",1,1,484+kx,414+ky,mar);
    Node *r141a = new Node(44,"141a",1,1,484+kx,386+ky,mar);
    Node *r142 = new Node(45,"142",1,1,484+kx,429+ky,mar);
    Node *r143 = new Node(46,"143",1,1,484+kx,447+ky,mar);
    Node *r144 = new Node(47,"144",1,1,484+kx,466+ky,mar);
    Node *r144a = new Node(48,"144a",1,1,500+kx,510+ky,mar);
    Node *r145 = new Node(49,"145",1,1,501+kx,510+ky,mar);

    Node *r146 = new Node(50,"146",1,1,517+kx,510+ky,mar);
    Node *r147 = new Node(51,"147",1,1,518+kx,510+ky,mar);
    Node *r148 = new Node(52,"148",1,1,563+kx,510+ky,mar);
    Node *r149 = new Node(53,"149",1,1,550+kx,510+ky,mar);
    Node *r150 = new Node(54,"150",1,1,593+kx,510+ky,mar);
    Node *r151 = new Node(55,"151",1,1,595+kx,510+ky,mar);
    Node *r151a = new Node(56,"151a",1,1,882+kx,455+ky,mar);


    Node *ME   = new Node(0,"MainEnter",1,1,687+kx,544+ky,mar);


    Node *r152 = new Node(57,"152",1,1,800+kx,518+ky,mar);
    Node *r152a = new Node(58,"152a",1,1,782+kx,518+ky,mar);
    Node *r153 = new Node(59,"153",1,1,781+kx,518+ky,mar);
    Node *r153a = new Node(60,"153a",1,1,799+kx,518+ky,mar);
    Node *r154 = new Node(61,"154",1,1,882+kx,511+ky,mar);
    Node *r155 = new Node(62,"155",1,1,857+kx,521+ky,mar);
    Node *r157a = new Node(63,"157a",1,1,881+kx,473+ky,mar);
    Node *r160 = new Node(64,"160",1,1,881+kx,452+ky,mar);
    Node *r161 = new Node(65,"161",1,1,881+kx,482+ky,mar);
    Node *r161a = new Node(66,"161a",1,1,881+kx,501+ky,mar);
    Node *r162 = new Node(67,"162",1,1,891+kx,521+ky,mar);
    Node *r162a = new Node(68,"162a",1,1,913+kx,522+ky,mar);
    Node *r163 = new Node(69,"163",1,1,951+kx,538+ky,mar);
    Node *r164 = new Node(70,"164",1,1,943+kx,521+ky,mar);
    Node *r165 = new Node(71,"165",1,1,958+kx,513+ky,mar);

    Node *r166 = new Node(72,"166",1,1,974+kx,513+ky,mar);
    Node *r166a = new Node(73,"166a",1,1,987+kx,513+ky,mar);
    Node *r167 = new Node(74,"167",1,1,1016+kx,514+ky,mar);
    Node *r168 = new Node(75,"168",1,1,1031+kx,515+ky,mar);
    Node *r169 = new Node(76,"169",1,1,1076+kx,516+ky,mar);
    Node *r170 = new Node(77,"170",1,1,1091+kx,518+ky,mar);
    Node *r170a = new Node(78,"170a",1,1,1104+kx,519+ky,mar);



    Node *r171 = new Node(79,"171",1,1,1162+kx,492+ky,mar);
    Node *r172 = new Node(80,"172",1,1,1162+kx,458+ky,mar);
    Node *r173 = new Node(81,"173",1,1,1162+kx,430+ky,mar);
    Node *r174 = new Node(82,"174",1,1,1162+kx,415+ky,mar);
    Node *r175 = new Node(83,"175",1,1,1162+kx,388+ky,mar);
    Node *r176 = new Node(84,"176",1,1,1162+kx,330+ky,mar);
    Node *r178 = new Node(85,"178",1,1,1162+kx,325+ky,mar);
    Node *r179 = new Node(86,"179",1,1,1162+kx,341+ky,mar);
    Node *r180 = new Node(87,"180",1,1,1162+kx,391+ky,mar);
    Node *r181 = new Node(88,"181",1,1,1162+kx,431+ky,mar);
    Node *r182 = new Node(89,"182",1,1,1162+kx,443+ky,mar);
    Node *r182a = new Node(90,"182a",1,1,1162+kx,467+ky,mar);
    Node *r183 = new Node(91,"183",1,1,1162+kx,457+ky,mar);
    Node *r184 = new Node(92,"184",1,1,1162+kx,499+ky,mar);
    Node *r185 = new Node(93,"185",1,1,1162+kx,516+ky,mar);
    Node *r186 = new Node(94,"186",1,1,1162+kx,528+ky,mar);



    r101->setNeighs(r102);
    r102->setNeighs(r101,r103);
    r103->setNeighs(r102,r104);
    r104->setNeighs(r103,r106);
    r106->setNeighs(r104,r107);
    r107->setNeighs(r106,r108);
    r108->setNeighs(r107,r109);
    r109->setNeighs(r108,r110);
    r110->setNeighs(r109,r111);
    r111->setNeighs(r110,r112);
    r112->setNeighs(r111,ln1);
    ln1->setNeighs(r112,r113,s1);
    r113->setNeighs(ln1,r114);
    r114->setNeighs(r113,r115);
    r115->setNeighs(r114,s1);
    s1->setNeighs(r115,ln1,r116);
    r116->setNeighs(s1,r117);
    r117->setNeighs(r116,r117a);
    r117a->setNeighs(r117,r118);
    r118->setNeighs(r117a,r119);
    r119->setNeighs(r118,r121);
    r121->setNeighs(r119,r120);
    r120->setNeighs(r121,r122);
    r122->setNeighs(r120,r123);
    r123->setNeighs(r122,r124);
    r124->setNeighs(r123,r125);
    r125->setNeighs(r124,rMainAccounting);
    rMainAccounting->setNeighs(r125,r126);
    r126->setNeighs(rMainAccounting,r127);
    r127->setNeighs(r126,r128);
    r128->setNeighs(r127,r129);
    r129->setNeighs(r128,r130);
    r130->setNeighs(r129,ln2);
    ln2->setNeighs(r130,r144,r145);

    r144->setNeighs(r143,ln2);
    r143->setNeighs(r144,r142);
    r142->setNeighs(r143,r141);
    r141->setNeighs(r142,r141a);
    r141a->setNeighs(r141,r140);
    r140->setNeighs(r141a,r131);
    r131->setNeighs(r140,r132);
    r132->setNeighs(r131,r139);
    r139->setNeighs(r132,r138);
    r138->setNeighs(r139,r137);
    r137->setNeighs(r138,r133);
    r133->setNeighs(r137,r134);
    r134->setNeighs(r133,r135a);
    r135a->setNeighs(r134,r136);
    r136->setNeighs(r135a,r135);
    r135->setNeighs(r136);




    r145->setNeighs(ln2,r144a);
    r144a->setNeighs(r145,r147);
    r147->setNeighs(r144a,r146);
    r146->setNeighs(r147,r149);
    r149->setNeighs(r146,r148);
    r148->setNeighs(r149,r150);
    r150->setNeighs(r148,r151);
    r151->setNeighs(r150,ln3);
    ln3->setNeighs(r151,ME,r153);
    ME->setNeighs(ln3);
    r153->setNeighs(ln3,r152a);
    r152a->setNeighs(r153,r153a);
    r153a->setNeighs(r152a,r152);
    r152->setNeighs(r153a,r155);
    r155->setNeighs(ln4,r152);
    ln4->setNeighs(r155,r154,r162);

    r154->setNeighs(ln4,r161a);
    r161a->setNeighs(r154,r151a);
    r151a->setNeighs(r161,r161a);
    r161->setNeighs(r157a,r151a);
    r157a->setNeighs(r161,r160);
    r160->setNeighs(r157a);

    r162->setNeighs(ln4,r162a);
    r162a->setNeighs(r162,r164);
    r164->setNeighs(r162a,r165,r163);
    r165->setNeighs(r164,r166);
    r163->setNeighs(r164);
    r166->setNeighs(r165,r166a);
    r166a->setNeighs(r166,r167);
    r167->setNeighs(r166a,r168);
    r168->setNeighs(r167,r169);
    r169->setNeighs(r168,r170);
    r170->setNeighs(r169,r170a);
    r170a->setNeighs(r170,ln5);
    ln5->setNeighs(r170a,r186);
    r186->setNeighs(ln4,r185);
    r185->setNeighs(r186,r184);
    r184->setNeighs(r185,r171);
    r171->setNeighs(r184,r182a);
    r182a->setNeighs(r172,r171);
    r172->setNeighs(r183,r182a);
    r183->setNeighs(r172,r182);
    r182->setNeighs(r183,r181);
    r181->setNeighs(r182,r173);
    r173->setNeighs(r181,r174);
    r174->setNeighs(r173,r180);
    r180->setNeighs(r174,r175);
    r175->setNeighs(r180,r179);
    r179->setNeighs(r175,r176);
    r176->setNeighs(r179,r178);
    r178->setNeighs(r176);






    Dij *df = new Dij();
    return df->DijF(mar[start],mar[end]);
}
