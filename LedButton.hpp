#ifndef ledButtonHPP
#define ledButtonHPP

#include"Component.hpp"
#include"DimmableLed.hpp"
#include"Button.hpp"


template<int portNumber>
class LedButton: public Button<portNumber>
{
private:
    DimmableLed& m_DimmableLed;
    bool m_IsDecreasing = false;
  
public:
    LedButton(DimmableLed& dimmableLed): Button<portNumber>("LedButton", false),m_DimmableLed(dimmableLed)
    {}

    LedButton(DimmableLed& dimmableLed, bool debug): Button<portNumber>("LedButton", debug),m_DimmableLed(dimmableLed)
    {}
    
    bool GetIsDecreasing() const{return m_IsDecreasing;} 
    virtual void OnShortButtonClick(){
      if(Component::IsDebug())
          Serial << Component::name() << ": Short Click\n";
      if (m_IsDecreasing)
        {
            if (m_DimmableLed.GetIntensity() > 0)
                m_DimmableLed.DecreaseLight();
                if(Component::IsDebug())
                    Serial << Component::name() << ": intensity decrease\n";
        }
        else
        {
          m_DimmableLed.SwitchOff();
          delay(300);
          m_DimmableLed.IncreaseLight();
          if(Component::IsDebug())
            Serial << Component::name() << ": intensity increase\n";
        } 
    }
    
    virtual void OnLongButtonClick(){
      if(Component::IsDebug())
          Serial << Component::name() << ": Long Click ----- switch mode\n";
      m_IsDecreasing = !m_IsDecreasing;   
    }
    
    virtual void OnVeryLongButtonClick(){
      if(Component::IsDebug())
          Serial << Component::name() << ": Very Long Click\n";
      m_DimmableLed.Blink();
    }
};

#endif
