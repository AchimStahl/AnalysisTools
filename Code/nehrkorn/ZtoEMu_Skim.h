#ifndef ZtoEMu_Skim_h
#define ZtoEMu_Skim_h

#include "Selection.h"
#include <vector>
#include "TString.h"

class ZtoEMu_Skim : public Selection {

 public:
  ZtoEMu_Skim(TString Name_, TString id_);
  virtual ~ZtoEMu_Skim();

  virtual void  Configure();
  virtual void Finish();

  enum cuts {TriggerOk=0,
	     PrimeVtx,
	     NMuPt,
	     NMuEta,
		 NMu,
	     NEPt,
	     NEEta,
		 NE,
		 ptthreshold,
		 charge,
	     NCuts};

 protected:
  virtual void doEvent();
  virtual void Store_ExtraDist();

 private:
  // Selection Variables
  
  std::vector<TH1D> NPV;
  std::vector<TH1D> mupt;
  std::vector<TH1D> mueta;
  std::vector<TH1D> ept;
  std::vector<TH1D> eeta;

  std::vector<TH1D> muptw;
  std::vector<TH1D> muetaw;
  std::vector<TH1D> eptw;
  std::vector<TH1D> eetaw;

  std::vector<TH1D> goodmuons;
  std::vector<TH1D> fakemuons;
  std::vector<TH1D> goodelectrons;
  std::vector<TH1D> fakeelectrons;
  std::vector<TH1D> discrgr20;
  std::vector<TH1D> discrsm20;

  double mu_ptlow,mu_pthigh,mu_eta,e_ptlow,e_pthigh,e_eta,jet_pt,jet_eta,jet_sum,zmin,zmax;
  int n_mu,n_e;
  
  double cosphi2d(double px1, double py1, double px2, double py2);
  double dxy(TLorentzVector fourvector, TVector3 poca, TVector3 vtx);
  double dz(TLorentzVector fourvector, TVector3 poca, TVector3 vtx);
  bool jetFromVtx(std::vector<int> vtx_track_idx, int leadingtrack_idx);
  bool isGoodVtx(unsigned int i);
  double vertexSignificance(TVector3 vec, unsigned int vertex);
  bool matchTrigger(unsigned int i, double dr, std::string trigger, std::string object);
  
  bool isTightMuon(unsigned int i);
  bool isTightMuon(unsigned int i, unsigned int j);
  bool isLooseMuon(unsigned int i);
  bool isFakeMuon(unsigned int i);
  bool isFakeMuon(unsigned int i, unsigned int j);
  double Muon_RelIso(unsigned int i);
  double Muon_AbsIso(unsigned int i);
  
  bool isMVATrigElectron(unsigned int i);
  bool isMVATrigNoIPElectron(unsigned int i);
  bool isMVANonTrigElectron(unsigned int i, unsigned int j);
  bool isTightElectron(unsigned int i);
  bool isTightElectron(unsigned int i, unsigned int j);
  bool isFakeElectron(unsigned int i);
  bool isFakeElectron(unsigned int i, unsigned int j);
  double Electron_RelIso(unsigned int i);
  double Electron_Aeff_R04(double Eta);
  double Electron_Aeff_R03(double Eta);
  
  double Fakerate(TLorentzVector vec, TH2D *fakeRateHist, std::string type);
  
  bool MVA_ID;
  TFile* FRFile;
  TFile* EmbEffFile;
  TH2D* ElectronFakeRate;
  TH2D* MuonFakeRate;
  TH2D* EmbEff;
  double fakeRate;
  double fakeRateMu;
  double fakeRateE;

};
#endif

