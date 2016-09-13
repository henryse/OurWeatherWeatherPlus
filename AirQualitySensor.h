int getAirQuality(void) {

    // Values in this routine are for 16 bit ADC

    int16_t sensor_value = adsAirQuality.readADC_SingleEnded(0);
    Serial.print("Sensor_Value=");
    Serial.print(sensor_value);
    Serial.print("--->");

    currentAirQualitySensor = sensor_value;


    // limit the conversion for the INT value

    if (currentAirQualitySensor < 32000) {
        INTcurrentAirQualitySensor = currentAirQualitySensor;
    } else {
        INTcurrentAirQualitySensor = 32000;
    }

    if (sensor_value > 11200) {
        Serial.println("Very High Pollution Detected");
        return 0;
    } else if (sensor_value > 6400) {
        Serial.println("High Pollution");
        return 1;
    } else if (sensor_value > 4800) {
        Serial.println("Medium Pollution");
        return 2;
    } else if (sensor_value > 3200) {
        Serial.println("Low Pollution");
        return 3;
    } else {
        Serial.println("Fresh Air");
        return 4;
    }

    // WARNING: Code never reached:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
    return -1;
#pragma clang diagnostic pop
}

String reportAirQuality(int latest) {

    switch (latest) {
        case (0):
            return "VHigh Pollu";

        case (1):
            return "High Pollu";

        case (2):
            return "Med Pollu";

        case (3):
            return "Low Pollu";

        case (4):
            return "Fresh Air";

        default: {
            return "NP";
        }
    }

    // WARNING: Code never reached:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
    return "UNKWN";
#pragma clang diagnostic pop
}

