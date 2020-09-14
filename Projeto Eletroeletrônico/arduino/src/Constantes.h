const bool ASSIST_CONTROL = false; // Enable assist control

// Timing Settings
const float LOOP_PERIOD = 0.03;       // The period (s) of the control loop
const float HOLD_IN_DURATION = 0.1;  // Duration (s) to pause after inhalation
const float MIN_PEEP_PAUSE = 0.05;    // Time (s) to pause after exhalation / before watching for an assisted inhalation
const float MAX_EX_DURATION = 1.00;   // Maximum exhale duration (s)

// Homing Settings
const float HOMING_VOLTS = 30;  // The speed (0-255) in volts to use during homing
const float HOMING_PAUSE = 1.0; // The pause time (s) during homing to ensure stability
const int BAG_CLEAR_POS = 50;   // The goal position (clicks) to retract to clear the bag
const int BAG_CLEAR_TOL = 10;   // The tolerance (clicks) to consider clear of bag

// Pins

#define DRIVER_EN  4       //Enable do driver DM322E - nível baixo habilita
#define DRIVER_DIR 5       //Direção de rotação - tempo mínimo entre sinal de direção e rotação: 5us
#define DRIVER_PUL 6       //Pulsos de controle - Ativado na borda de subida, largura mínima: 2,5us

#define LED_PATIENT_EFFORT 9          //Led de indicação de esforço do paciente

#define SWITCH_CONFIRM 10       //botão de confirmação
#define SWITCH_POSITION 11      //Chave de fim de curso
#define SWITCH_MODE 2           //Modo de ventilação

#define POT_PIP A2               //Pressão inspiratória de pico
#define POT_INSP_TIME A3         //tempo de inspiração
#define POT_FREQUENCE A4         //frequência respiratória
#define POT_SENSIBILITY A5       //sensibilidade no modo assistido

#define SENSOR_PRESSURE_1 A0


// Limites dos controles
const int FREQ_MIN = 1;
const int FREQ_MAX = 60;
const int FREQ_RESOLUC = 1;
const float TINSP_MIN = 0.3;
const float TINSP_MAX = 6;
const float TINSP_RESOLUC = 0.1;
const int PIP_MIN = 5;
const int PIP_MAX = 55; 
const int PIP_RESOLUC = 0.2; 
const float SENS_MIN = 0.4;
const float SENS_MAX = 2;
const float SENS_RESOLUC = 0.2;
const int VOLTAGE_CONVERSOR = 5/1023; // conversão do sinal digital para valores de tensão.


//sensor de pressão

//Tensão a 120 cmH2O = 4.5V nominal (entre 4.4 e 4.6)
//Tensão a 0 cmH2O = 0.35V nominal (entre 0.30 e 0.40)
//Tensão a -10 cmH2O = 0.28V novinal (entre 0.23 e 0.33)
const float PRESSURE_CONVERSOR = VOLTAGE_CONVERSOR * (120 + 10) / (4.5 - 0.28);

// Safety settings
const float MAX_PRESSURE = 40.0;        // Trigger high pressure alarm
const float MIN_PLATEAU_PRESSURE = 5.0; // Trigger low pressure alarm
const float MAX_RESIST_PRESSURE = 2.0;  // Trigger high-resistance notification
const float MIN_TIDAL_PRESSURE = 5.0;   // Trigger no-tidal-pressure alarm
const float VOLUME_ERROR_THRESH = 50.0; // Trigger incomplete breath alarm
const int MAX_MOTOR_CURRENT = 1000;     // Trigger mechanical failure alarm. Units (10mA)
const float TURNING_OFF_DURATION = 5.0; // Turning-off alarm is on for this duration (s)
const float MECHANICAL_TIMEOUT = 1.0;   // Time to wait for the mechanical cycle to finish before alarming

// PID values for auto-tuned for PG188
const unsigned long QPPS = 2000;
const float VKP = 6.38650;
const float VKI = 0.0;
const float VKD = 0.0;
const float PKP = 70.0;
const float PKI = 0.2;
const float PKD = 200.0;
const unsigned long KI_MAX = 10;
const unsigned long DEADZONE = 0;
const unsigned long MIN_POS = -100;
const unsigned long MAX_POS = 700;
const unsigned long VEL_MAX = 1800;     // Maximum velocity (clicks/s) to command
const unsigned long ACC_MAX = 200000;   // Maximum acceleration (clicks/s^2) to command

#endif
