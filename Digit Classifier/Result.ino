#include "model.h"

void loop() {
    if (!capture_still()) {
        Serial.println("Failed capture");
        delay(2000);

        return;
    }

    Serial.print("Number: ");
    Serial.println(classIdxToName(predict(features)));
    delay(3000);
}
