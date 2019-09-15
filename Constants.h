//
// Created by Denis on 2019-08-04.
//

#ifndef KURSWORK_CONSTANTS_H
#define KURSWORK_CONSTANTS_H


namespace Constants{
    const unsigned int WindowSizeX  = 1920;
    const unsigned int WindowSizeY  = 1080;

    const float SpeedRacket         = 2.5;
    const float HeightRacket        = 50;
    const float WidthRacket         = 300;

    const float RadiusBall          = 25;
    const float SpeedBall           = 0.5;
    const float HeightforRacket     = 50;
    const float PositionBallY       = Constants::WindowSizeY - Constants::HeightRacket - Constants::HeightforRacket / 2 - Constants::RadiusBall * 3;

    const int   QuantityBlocks      = 20;

    const float HeightBlock         = WindowSizeY / (float)QuantityBlocks;
    const float WidthBlock          = WindowSizeX / (float)QuantityBlocks;

    const int   BlockX              = 10;
    const int   BlockY              = 2;

    const int   FreeSpaceLeftRight  = (QuantityBlocks - BlockX) / 2;
    const int   FreeSpaceTop        = 5;
    const float FreeSpaceNearBlocks = 10;

    const float HeightBonus         = 10;
    const float WidthBonus          = 10;

    const float SpeedBlock          = 0.3;

    const float SpeedBonus          = 0.3;

    const float ChangeSpeed         = 0.1;
    const float ChangeWidth         = 0.2;
    const float ChangeRadiusCoef    = 0.1;

    const float BonusTime           = 5000;

    //int PercentBonus(int how) {return 100 / how;}

}



#endif //KURSWORK_CONSTANTS_H
