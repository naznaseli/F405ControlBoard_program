#pragma once

class SwerveDrive
{
public:
    SwerveDrive();
    ~SwerveDrive();
private:
    Motor* m_motorSteerFL;
    Motor* m_motorSteerFR;
    Motor* m_motorSteerRL;
    Motor* m_motorSteerRR;
    Motor* m_motorDriveFL;
    Motor* m_motorDriveFR;
    Motor* m_motorDriveRL;
    Motor* m_motorDriveRR;
    Encoder* m_encSteerFL;
    Encoder* m_encSteerFR;
    Encoder* m_encSteerRL;
    Encoder* m_encSteerRR;
    Encoder* m_encDriveFL;
    Encoder* m_encDriveFR;
    Encoder* m_encDriveRL;
    Encoder* m_encDriveRL;
    Potentio* m_potentioSteerFL;
    Potentio* m_potentioSteerFL;
    Potentio* m_potentioSteerFL;
    Potentio* m_potentioSteerFL;
};
