#include "aimassist.h"

void assist::run()
{

    //        const int appWidth = app.getWidth();
    //        const int appHeight = app.getHeight();

    //        const int widthFactor = appWidth / osuMapWidth;
    //        const int heightFactor = appHeight / osuMapHeight;

    //        std::cout << "To end the assistant, press the key combination: 'CTRL + C' or close the console window\n\n";
    //        while (true)
    //        {
    //            Sleep(waitMoment);

    //            std::string mapPath;

    //            const AppHandler::ResultCode isGetMapPath = app.getMapPath(&mapPath);
    //            if (isGetMapPath != AppHandler::ResultCode::success)
    //            {
    //                std::cerr << "Map is not found. Result Code: " << isGetMapPath << std::endl;

    //                continue;
    //            }

    //            OsuDecoder decoder(mapPath.c_str());

    //            const OsuDecoder::ResultCode decodeStatus = decoder.getStatus();
    //            if (decodeStatus != OsuDecoder::ResultCode::success)
    //            {
    //                std::cerr << "Cannot decode the map. ResultCode: " << decodeStatus << std::endl;

    //                continue;
    //            }

    //            const float sliderMultiplier = std::stof(decoder.difficulty.sliderMultiplier);
    //            const float sv = std::stof(decoder.difficulty.sliderTickRate);

    //            const int circleRadius = 54.4f - 4.48f * std::stof(decoder.difficulty.circleSize);
    //            int lastTime = 0;

    //            CursorHandler cursor;

    //            for (const auto &hitObject : decoder.hitObjects)
    //            {
    //                const int noteX = hitObject.x * widthFactor;
    //                const int noteY = hitObject.y * heightFactor + heightOffset;

    //                const int tapTime = hitObject.time - lastTime;

    //                switch (hitObject.type)
    //                {
    //                case HitObjectType::HIT_CIRCLE:
    //                    cursor.moveToPoint(noteX, noteY, tapTime, circleRadius);
    //                    break;

    //                case HitObjectType::SLIDER:
    //                    const int beatLengthIndex = binarySearch(decoder.timingPoints, hitObject.time);
    //                    const double beatLength = decoder.timingPoints[beatLengthIndex].beatLength;

    //                    const int repeatDuration = hitObject.pixelLength / (sliderMultiplier * 100 * sv) * beatLength + 1;
    //                    const bool isRoundType = hitObject.curveType == 'P';

    //                    cursor.moveToCurve(noteX, noteY, tapTime, circleRadius, hitObject.repeats, repeatDuration, hitObject.curvePoints, isRoundType);
    //                    break;
    //                }

    //                lastTime = hitObject.time;
    //            }
    //        }


}
