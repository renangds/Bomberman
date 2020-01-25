void define_coordinates(){
    HERO.front_clip[0].x = 1;
    HERO.front_clip[0].y = 1;
    HERO.front_clip[0].h = 71;
    HERO.front_clip[0].w = 61;

    HERO.front_clip[1].x = 73;
    HERO.front_clip[1].y = 0;
    HERO.front_clip[1].h = 72;
    HERO.front_clip[1].w = 61;

    HERO.front_clip[2].x = 145;
    HERO.front_clip[2].y = 0;
    HERO.front_clip[2].h = 72;
    HERO.front_clip[2].w = 61;


    HERO.behind_clip[0].x = 0;
    HERO.behind_clip[0].y = 216;
    HERO.behind_clip[0].h = 72;
    HERO.behind_clip[0].w = 60;

    HERO.behind_clip[1].x = 72;
    HERO.behind_clip[1].y = 216;
    HERO.behind_clip[1].h = 72;
    HERO.behind_clip[1].w = 60;

    HERO.behind_clip[2].x = 144;
    HERO.behind_clip[2].y = 216;
    HERO.behind_clip[2].h = 72;
    HERO.behind_clip[2].w = 60;

    HERO.left_clip[0].x = 1;
    HERO.left_clip[0].y = 73;
    HERO.left_clip[0].h = 71;
    HERO.left_clip[0].w = 62;

    HERO.left_clip[1].x = 73;
    HERO.left_clip[1].y = 73;
    HERO.left_clip[1].h = 71;
    HERO.left_clip[1].w = 62;

    HERO.left_clip[2].x = 145;
    HERO.left_clip[2].y = 73;
    HERO.left_clip[2].h = 71;
    HERO.left_clip[2].w = 62;

    HERO.right_clip[0].x = 0;
    HERO.right_clip[0].y = 145;
    HERO.right_clip[0].h = 71;
    HERO.right_clip[0].w = 60;

    HERO.right_clip[1].x = 70;
    HERO.right_clip[1].y = 145;
    HERO.right_clip[1].h = 71;
    HERO.right_clip[1].w = 62;

    HERO.right_clip[2].x = 142;
    HERO.right_clip[2].y = 145;
    HERO.right_clip[2].h = 71;
    HERO.right_clip[2].w = 62;

    //Heart Clips

    HERO.heart_clip[0].x = 0;
    HERO.heart_clip[0].y = 0;
    HERO.heart_clip[0].h = 42;
    HERO.heart_clip[0].w = 42;

    HERO.heart_clip[1].x = 143;
    HERO.heart_clip[1].y = 0;
    HERO.heart_clip[1].h = 42;
    HERO.heart_clip[1].w = 42;

    //Frog Clips

    ENEMY1.clips[0].x = 85;
    ENEMY1.clips[0].y = 22;
    ENEMY1.clips[0].h = 46;
    ENEMY1.clips[0].w = 46;

    ENEMY1.clips[1].x = 153;
    ENEMY1.clips[1].y = 12;
    ENEMY1.clips[1].h = 53;
    ENEMY1.clips[1].w = 54;

    //Alguns objetos destrutíveis e indestrutíveis

    IOBJ.indest.x = 49;
    IOBJ.indest.y = 2785;
    IOBJ.indest.h = 47;
    IOBJ.indest.w = 47;

    IOBJ.destructive.x = 6;
    IOBJ.destructive.y = 12;
    IOBJ.destructive.w = 44;
    IOBJ.destructive.h = 42;

    IOBJ.barrel.x = 1251;
    IOBJ.barrel.y = 1824;
    IOBJ.barrel.w = 47;
    IOBJ.barrel.h = 48;

    IOBJ.blue_chest.x = 524;
    IOBJ.blue_chest.y = 12;
    IOBJ.blue_chest.h = 42;
    IOBJ.blue_chest.w = 45;

    //Explosões

    EXPLOSION.explosion_up[0].x = 150;
    EXPLOSION.explosion_up[0].y = 2;
    EXPLOSION.explosion_up[0].h = 42;
    EXPLOSION.explosion_up[0].w = 47;

    EXPLOSION.explosion_up[1].x = 201;
    EXPLOSION.explosion_up[1].y = 2;
    EXPLOSION.explosion_up[1].h = 42;
    EXPLOSION.explosion_up[1].w = 47;

    EXPLOSION.explosion_up[2].x = 248;
    EXPLOSION.explosion_up[2].y = 88;
    EXPLOSION.explosion_up[2].h = 43;
    EXPLOSION.explosion_up[2].w = 47;

    EXPLOSION.explosion_up[3].x = 1;
    EXPLOSION.explosion_up[3].y = 131;
    EXPLOSION.explosion_up[3].h = 43;
    EXPLOSION.explosion_up[3].w = 47;

    //Baixo

    EXPLOSION.explosion_down[0].x = 297;
    EXPLOSION.explosion_down[0].y = 88;
    EXPLOSION.explosion_down[0].h = 43;
    EXPLOSION.explosion_down[0].w = 47;

    EXPLOSION.explosion_down[1].x = 345;
    EXPLOSION.explosion_down[1].y = 88;
    EXPLOSION.explosion_down[1].h = 43;
    EXPLOSION.explosion_down[1].w = 47;

    EXPLOSION.explosion_down[2].x = 250;
    EXPLOSION.explosion_down[2].y = 2;
    EXPLOSION.explosion_down[2].h = 42;
    EXPLOSION.explosion_down[2].w = 47;

    EXPLOSION.explosion_down[3].x = 348;
    EXPLOSION.explosion_down[3].y = 2;
    EXPLOSION.explosion_down[3].h = 42;
    EXPLOSION.explosion_down[3].w = 47;

    //Left

    EXPLOSION.explosion_left[0].x = 51;
    EXPLOSION.explosion_left[0].y = 46;
    EXPLOSION.explosion_left[0].h = 41;
    EXPLOSION.explosion_left[0].w = 47;

    EXPLOSION.explosion_left[1].x = 100;
    EXPLOSION.explosion_left[1].y = 46;
    EXPLOSION.explosion_left[1].h = 41;
    EXPLOSION.explosion_left[1].w = 47;

    EXPLOSION.explosion_left[2].x = 150;
    EXPLOSION.explosion_left[2].y = 46;
    EXPLOSION.explosion_left[2].h = 41;
    EXPLOSION.explosion_left[2].w = 47;

    EXPLOSION.explosion_left[3].x = 249;
    EXPLOSION.explosion_left[3].y = 46;
    EXPLOSION.explosion_left[3].h = 41;
    EXPLOSION.explosion_left[3].w = 47;

    //Right

    EXPLOSION.explosion_right[0].x = 347;
    EXPLOSION.explosion_right[0].y = 45;
    EXPLOSION.explosion_right[0].h = 41;
    EXPLOSION.explosion_right[0].w = 47;

    EXPLOSION.explosion_right[1].x = 1;
    EXPLOSION.explosion_right[1].y = 88;
    EXPLOSION.explosion_right[1].h = 41;
    EXPLOSION.explosion_right[1].w = 47;

    EXPLOSION.explosion_right[2].x = 51;
    EXPLOSION.explosion_right[2].y = 88;
    EXPLOSION.explosion_right[2].h = 41;
    EXPLOSION.explosion_right[2].w = 47;

    EXPLOSION.explosion_right[3].x = 149;
    EXPLOSION.explosion_right[3].y = 88;
    EXPLOSION.explosion_right[3].h = 41;
    EXPLOSION.explosion_right[3].w = 47;

    EXPLOSION.explosion_center.x = 346;
    EXPLOSION.explosion_center.y = 132;
    EXPLOSION.explosion_center.h = 42;
    EXPLOSION.explosion_center.w = 48;

    //Portal

    PORTAL.portal_animation[0].x = 150;
    PORTAL.portal_animation[0].y = 295;
    PORTAL.portal_animation[0].h = 40;
    PORTAL.portal_animation[0].w = 36;

    PORTAL.portal_animation[1].x = 198;
    PORTAL.portal_animation[1].y = 295;
    PORTAL.portal_animation[1].h = 40;
    PORTAL.portal_animation[1].w = 36;

    PORTAL.portal_animation[2].x = 246;
    PORTAL.portal_animation[2].y = 295;
    PORTAL.portal_animation[2].h = 40;
    PORTAL.portal_animation[2].w = 36;

    //Itens do jogo

    ITEMS.bomb_activate.x = 717;
    ITEMS.bomb_activate.y = 54;
    ITEMS.bomb_activate.h = 48;
    ITEMS.bomb_activate.w = 48;

    ITEMS.bomb_exploded.x = 669;
    ITEMS.bomb_exploded.y = 60;
    ITEMS.bomb_exploded.h = 36;
    ITEMS.bomb_exploded.w = 42;

    //Ponto extra
    ITEMS.items_bonus[1].x = 411;
    ITEMS.items_bonus[1].y = 159;
    ITEMS.items_bonus[1].h = 45;
    ITEMS.items_bonus[1].w = 45;

    //Temp extra
    ITEMS.items_bonus[0].x = 258;
    ITEMS.items_bonus[0].y = 156;
    ITEMS.items_bonus[0].h = 48;
    ITEMS.items_bonus[0].w = 45;

    //Vida extra

    ITEMS.items_bonus[2].x = 513;
    ITEMS.items_bonus[2].y = 312;
    ITEMS.items_bonus[2].h = 42;
    ITEMS.items_bonus[2].w = 48;

    //Chave

    ITEMS.items_bonus[3].x = 264;
    ITEMS.items_bonus[3].y = 360;
    ITEMS.items_bonus[3].h = 48;
    ITEMS.items_bonus[3].w = 36;

    //Portal de início

    PORTAL_RESPAWN.portal.x = 8;
    PORTAL_RESPAWN.portal.y = 274;
    PORTAL_RESPAWN.portal.h = 37;
    PORTAL_RESPAWN.portal.w = 46;
}