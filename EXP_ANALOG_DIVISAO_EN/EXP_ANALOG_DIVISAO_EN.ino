#include "OptaBlue.h"
 
#define PERIODIC_UPDATE_TIME 500
#define DELAY_AFTER_SETUP 5000
 
using namespace Opta;
 
/* -------------------------------------------------------------------------- */
void printExpansionType(ExpansionType_t t) {
/* -------------------------------------------------------------------------- */
  if(t == EXPANSION_NOT_VALID) {
    Serial.print("Unknown!");
  }
  else if(t == EXPANSION_OPTA_DIGITAL_MEC) {
    Serial.print("Opta --- DIGITAL [Mechanical]  ---");
  }
  else if(t == EXPANSION_OPTA_DIGITAL_STS) {
    Serial.print("Opta --- DIGITAL [Solid State] ---");
  }
  else if(t == EXPANSION_DIGITAL_INVALID) {
    Serial.print("Opta --- DIGITAL [!!Invalid!!] ---");
  }
  else if(t == EXPANSION_OPTA_ANALOG) {
    Serial.print("~~~ Opta  ANALOG ~~~");
  }
  else {
    Serial.print("Unknown!");
  }
}
 
/* -------------------------------------------------------------------------- */
void printExpansionInfo() {
/* -------------------------------------------------------------------------- */
  static long int start = millis();
 
  if(millis() - start > 5000) {
    start = millis();
    Serial.print("Number of expansions: ");
    Serial.println(OptaController.getExpansionNum());
 
    for(int i = 0; i < OptaController.getExpansionNum(); i++) {
      Serial.print("Expansion n. ");
      Serial.print(i);
      Serial.print(" type ");
      printExpansionType(OptaController.getExpansionType(i));
      Serial.print(" I2C address ");
      Serial.println(OptaController.getExpansionI2Caddress(i));
    }
  }  
}
 
/* -------------------------------------------------------------------------- */
/*                                 SETUP                                      */
/* -------------------------------------------------------------------------- */
void setup() {
/* -------------------------------------------------------------------------- */
  Serial.begin(115200);
  delay(2000);
 
  OptaController.begin();
 

      //CONFIGURATION IN EXP0 AS READING (ONLY OA_CH0 - I1) 
      AnalogExpansion::beginChannelAsAdc(OptaController, 0, // EXPANSION ADDRESS
                                                        OA_CH_0, // READING CHANNEL
                                                        OA_VOLTAGE_ADC, // READING TYPE (ADC)
                                                        true, // enable pull down
                                                        false, // disable rejection
                                                        false, // disable diagnostic
                                                        0); // disable averaging

      //CONFIGURATION IN EXP0 AS READING (ONLY OA_CH1 - I2)
      AnalogExpansion::beginChannelAsAdc(OptaController, 0, // EXPANSION ADDRESS
                                                        OA_CH_1, // READING CHANNEL
                                                        OA_VOLTAGE_ADC, // READING TYPE (ADC)
                                                        true, // enable pull down
                                                        false, // disable rejection
                                                        false, // disable diagnostic
                                                        0); // disable averaging
                                                        

      //CONFIGURATION IN EXP0 AS READING (ONLY OA_CH2 - I3)
      AnalogExpansion::beginChannelAsAdc(OptaController, 0, // EXPANSION ADDRESS
                                                        OA_CH_2, // READING CHANNEL
                                                        OA_VOLTAGE_ADC, // READING TYPE (ADC)
                                                        true, // enable pull down
                                                        false, // disable rejection
                                                        false, // disable diagnostic
                                                        0); // disable averaging


      //CONFIGURATION IN EXP0 AS READING (ONLY OA_CH3 - I4)
      AnalogExpansion::beginChannelAsAdc(OptaController, 0, // EXPANSION ADDRESS
                                                        OA_CH_3, // READING CHANNEL
                                                        OA_VOLTAGE_ADC, // READING TYPE (ADC)
                                                        true, // enable pull down
                                                        false, // disable rejection
                                                        false, // disable diagnostic
                                                        0); // disable averaging

      //CONFIGURATION IN EXP0 AS READING (ONLY OA_CH4 - O1)
      AnalogExpansion::beginChannelAsAdc(OptaController, 0, // EXPANSION ADDRESS
                                                        OA_CH_4, // READING CHANNEL
                                                        OA_VOLTAGE_ADC, // READING TYPE (ADC)
                                                        true, // enable pull down
                                                        false, // disable rejection
                                                        false, // disable diagnostic
                                                        0); // disable averaging 

      //CONFIGURATION IN EXP0 AS READ (ONLY OA_CH5 - I5)
      AnalogExpansion::beginChannelAsAdc(OptaController, 0, // EXPANSION ADDRESS
                                                        OA_CH_5, // READING CHANNEL
                                                        OA_VOLTAGE_ADC, // READING TYPE (ADC)
                                                        true, // enable pull down
                                                        false, // disable rejection
                                                        false, // disable diagnostic
                                                        0); // disable averaging

/* -------------------------------------------------------------------------- */

      //CONFIGURATION ON EXP1 AS DAC (ONLY OA_CH0 - I1)
      AnalogExpansion::beginChannelAsDac(OptaController,
                                         1, //EXPANSION ADDRESS
                                         OA_CH_0, //DAC OUTPUT CHANNEL
                                         OA_VOLTAGE_DAC, //OUTPUT TYPE (DAC)
                                         true,
                                         false,
                                         OA_SLEW_RATE_0);

      //CONFIGURATION ON EXP1 AS DAC (ONLY OA_CH1 - I2)
      AnalogExpansion::beginChannelAsDac(OptaController,
                                         1, //EXPANSION ADDRESS
                                         OA_CH_1, //DAC OUTPUT CHANNEL
                                         OA_VOLTAGE_DAC, //OUTPUT TYPE (DAC)
                                         true,
                                         false,
                                         OA_SLEW_RATE_0);


      //CONFIGURATION ON EXP1 AS DAC (ONLY OA_CH2 - I3)
      AnalogExpansion::beginChannelAsDac(OptaController,
                                         1, //EXPANSION ADDRESS
                                         OA_CH_2, //DAC OUTPUT CHANNEL
                                         OA_VOLTAGE_DAC, //OUTPUT TYPE (DAC)
                                         true,
                                         false,
                                         OA_SLEW_RATE_0);


      //CONFIGURATION ON EXP1 AS DAC (ONLY OA_CH3 - I4)
      AnalogExpansion::beginChannelAsDac(OptaController,
                                         1, //EXPANSION ADDRESS
                                         OA_CH_3, //DAC OUTPUT CHANNEL
                                         OA_VOLTAGE_DAC, //OUTPUT TYPE (DAC)
                                         true,
                                         false,
                                         OA_SLEW_RATE_0);


      //CONFIGURATION ON EXP1 AS DAC (ONLY OA_CH4 - O1)
      AnalogExpansion::beginChannelAsDac(OptaController,
                                         1, //EXPANSION ADDRESS
                                         OA_CH_4, //DAC OUTPUT CHANNEL
                                         OA_VOLTAGE_DAC, //OUTPUT TYPE (DAC)
                                         true,
                                         false,
                                         OA_SLEW_RATE_0);


      //CONFIGURATION ON EXP1 AS DAC (ONLY OA_CH5 - I5)
      AnalogExpansion::beginChannelAsDac(OptaController,
                                         1, //EXPANSION ADDRESS
                                         OA_CH_5, //DAC OUTPUT CHANNEL
                                         OA_VOLTAGE_DAC, //OUTPUT TYPE (DAC)
                                         true,
                                         false,
                                         OA_SLEW_RATE_0);

}
 
/* -------------------------------------------------------------------------- */
void optaAnalogTask() {
/* -------------------------------------------------------------------------- */
  static long int start = millis();
  if (millis() - start > PERIODIC_UPDATE_TIME) {
    start = millis();

    AnalogExpansion exp0 = OptaController.getExpansion(0); // Reading expansion
    AnalogExpansion exp1 = OptaController.getExpansion(1); // Mirroring Expansion

    if (exp0 && exp1) {
      // Reading values ​​from exp0 and mirroring them in exp1
      uint16_t dac_value;

      // I1 -> O1
      dac_value = map(exp0.analogRead(OA_CH_0), 0, 65535, 0, 7490);
      exp1.setDac(OA_CH_0, dac_value);
      Serial.println("Espelhando valor " + String(dac_value) + " para OA_CH_0");

      // I2 -> O2
      dac_value = map(exp0.analogRead(OA_CH_1), 0, 65535, 0, 7490);
      exp1.setDac(OA_CH_1, dac_value);
      Serial.println("Espelhando valor " + String(dac_value) + " para OA_CH_1");

      // I3 -> O3
      dac_value = map(exp0.analogRead(OA_CH_2), 0, 65535, 0, 7490);
      exp1.setDac(OA_CH_2, dac_value);
      Serial.println("Espelhando valor " + String(dac_value) + " para OA_CH_2");

      // I4 -> O4
      dac_value = map(exp0.analogRead(OA_CH_3), 0, 65535, 0, 7490);
      exp1.setDac(OA_CH_3, dac_value);
      Serial.println("Espelhando valor " + String(dac_value) + " para OA_CH_3");

      // I5 -> O5
      dac_value = map(exp0.analogRead(OA_CH_4), 0, 65535, 0, 7490);
      exp1.setDac(OA_CH_4, dac_value);
      Serial.println("Espelhando valor " + String(dac_value) + " para OA_CH_4");

      // I6 -> O6
      dac_value = map(exp0.analogRead(OA_CH_5), 0, 65535, 0, 7490);
      exp1.setDac(OA_CH_5, dac_value);
      Serial.println("Espelhando valor " + String(dac_value) + " para OA_CH_5");
    }
  }
}

 
/* -------------------------------------------------------------------------- */
/*                                  LOOP                                      */
/* -------------------------------------------------------------------------- */
void loop() {
/* -------------------------------------------------------------------------- */    
  OptaController.update();
  optaAnalogTask();
 
}