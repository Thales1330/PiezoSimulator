#include "MainFrame.h"
#include <wx/msgdlg.h>
#include<complex>
#include<stdio.h>
#include<math.h>
#include <wx/app.h>
#include <wx/event.h>
#include "ChartView.h"
#include "ElementPlotData.h"
#include <wx/image.h>
#include <vector>

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBase(parent)
{
}
  

MainFrame::~MainFrame()
{
}

void MainFrame::OnbtnSimularClick(wxCommandEvent& event)
{
    double massa = 0, dm = 0, cm = 0, cp = 0, alfa = 0, passo = 0, r = 0, deflexao = 0, freq = 0, F = 0, tempsimu = 0;

    m_controlMassa->GetValue().ToDouble(&massa);
    m_controlDm->GetValue().ToDouble(&dm);
    m_controlCm->GetValue().ToDouble(&cm);
    m_controlCp->GetValue().ToDouble(&cp);
    m_controlAlfa->GetValue().ToDouble(&alfa);
    m_controlR->GetValue().ToDouble(&r);
    m_controlPasso->GetValue().ToDouble(&passo);
    m_controlDeflexao->GetValue().ToDouble(&deflexao);
    m_controlFrequencia->GetValue().ToDouble(&freq);
    m_controlF->GetValue().ToDouble(&F);
    m_controlTempSimu->GetValue().ToDouble(&tempsimu);

    if (massa == 0 && dm == 0 && cm == 0 && cp == 0 && alfa == 0 && passo == 0 && r == 0 && deflexao == 0 && freq == 0 && F == 0 && tempsimu==0)
    {
        wxMessageBox(wxString::Format("Digite valores diferente de 0 para realizar os cálculos"));
        m_controlMassa->Clear();
        m_controlDm->Clear();
        m_controlCm->Clear();
        m_controlCp->Clear();
        m_controlAlfa->Clear();
        m_controlR->Clear();
        m_controlPasso->Clear();
        m_controlDeflexao->Clear();
        m_controlFrequencia->Clear();
        m_controlF->Clear();
        m_controlTempSimu->Clear();
    }
    
    std::complex<double> j = { 0,1 };

   // wxMessageBox(wxString::Format("Massa = %.2f \nDm = %.2f \nCm = %.2f \nAlfa = %.2f \nCp = %.2f \nR = %.2f \nPasso = %.2f \nDeflexão = %.2f ", massa, dm, cm, alfa, cp, r, passo, deflexao));
    std::complex<double> Y11 = ((alfa*alfa) / (j * freq * massa + dm + (cm / j * freq)))+(1.0/(r+1.0/(j*freq*cp)));
    std::complex<double> Y12 = (alfa/(j*freq*massa+dm+ (cm / j * freq)));
    std::complex<double> Y22 = (1.0 / (j * freq * massa + dm + (cm / j * freq)));
    std::complex<double> Y21 = Y12;
    wxMessageBox(wxString::Format("Admitâncias \n\nY11= %.4f %.4fi\n Y12=Y21=%.4f %.4fi\n Y22= %.4f %.4fi", std::real(Y11), std::imag(Y11), std::real(Y12), std::imag(Y12), std::real(Y22), std::imag(Y22)));
 
    std::complex<double> dt(std::complex<double>, double, double, double, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>);
    double t0 = 0;
    std::vector<double> tempo;
    std::vector<std::complex<double>> tensaoComplexo;
    std::vector<std::complex<double>> t;
    std::vector<double> tensaoAbs;
    std::vector<double> correnteAbs;
    t.push_back(t0);
    double sTempo = 0;
    int numpassos = static_cast<int>(tempsimu / passo);
    for (int i = 0; (i < numpassos); ++i) {
        tempo.emplace_back(sTempo);
        tensaoComplexo.emplace_back((deflexao - F * sin(sTempo * 2* M_PI *freq) * Y22) / Y21);
        sTempo += passo;
        
        if (i < numpassos - 1) {
            t.push_back(t[i] + passo * (dt(t[i], deflexao, F, freq, Y11, Y21, Y12, Y22)));
        }
    }
    
    for (auto tensao : tensaoComplexo) {
        tensaoAbs.emplace_back(std::abs(tensao));
    }

    for (auto corrente : t) {
        correnteAbs.emplace_back(std::abs(corrente));

    }

    std::vector<ElementPlotData> plotDataList;

    ElementPlotData plotData;
    plotData.SetName(wxT("Piezo"));
    plotData.SetCurveType(ElementPlotData::CurveType::CT_SIMULAR);
    plotData.AddData(tensaoAbs, wxT("Tensao"));
    plotData.AddData(correnteAbs, wxT("Corrente"));
    plotDataList.push_back(plotData);


    ChartView* cView = new ChartView(nullptr, plotDataList, tempo);
    cView->Show();

}
void MainFrame::OnbtnLimparClick(wxCommandEvent& event)
{
    m_controlMassa->Clear();
    m_controlDm->Clear();
    m_controlCm->Clear();
    m_controlCp->Clear();
    m_controlAlfa->Clear();
    m_controlR->Clear();
    m_controlPasso->Clear();
    m_controlDeflexao->Clear();
    m_controlFrequencia->Clear();
    m_controlF->Clear();
    m_controlTempSimu->Clear();
}
std::complex<double> dt(std::complex<double>  t, double deflexao, double F, double freq, std::complex<double> Y11, std::complex<double> Y21, std::complex<double> Y12, std::complex<double> Y22)

{
    
   return(((Y11/Y21)*(deflexao-F*sin(2* M_PI *freq*t)*Y22))+(Y12*F*sin(2 * M_PI *freq*t)));
}