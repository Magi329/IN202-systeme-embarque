#ifndef dimmableLedHPP
#define dimmableLedHPP

#include"Component.hpp"

class DimmableLed: public Component
{
private:
    int m_Intensity;
    uint32_t m_PortNumber;
    bool m_IsBlinking;
public:
    DimmableLed(uint32_t thePortNumber, const char* theName, bool debug = false): Component(theName, debug), m_PortNumber(thePortNumber),
    m_Intensity(0), m_IsBlinking(false) {
    pinMode(m_PortNumber, OUTPUT); 
  }
    
    uint32_t GetPortNumber() const { return m_PortNumber; }
    int GetIntensity() const {return m_Intensity;}

    bool IsSwitchedOn() const {
      Serial.print(m_Intensity);
      return m_Intensity>0;}

    bool DecreaseLight(){
      if (m_Intensity == 0){
        return false;
      } else {
        while (m_Intensity != 0){
          m_Intensity -=15;
          analogWrite(m_PortNumber, m_Intensity);
          delay(100);
        }
      return true;
      }
    };
    bool IncreaseLight(){
        while (m_Intensity != 255){
          m_Intensity +=15;
          analogWrite(m_PortNumber, m_Intensity);
          delay(100);
        }
      return true;
        
    };

    void SwitchOn(){
      m_Intensity = 255;
      analogWrite(m_PortNumber,m_Intensity);
    };
    void SwitchOff(){
      m_Intensity = 0;
      analogWrite(m_PortNumber,m_Intensity);
    }; 

    void Blink(){
      //m_IsBlinking = !m_IsBlinking;
      if(!m_IsBlinking){
        for(int i=0; i<25; i++){
          analogWrite(m_PortNumber,0);
          delay(100);
          analogWrite(m_PortNumber,200);
          delay(100);
        }
      }
    }
};
#endif
