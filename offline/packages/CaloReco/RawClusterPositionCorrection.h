#ifndef CALORECO_RAWCLUSTERPOSITIONCORRECTION_H
#define CALORECO_RAWCLUSTERPOSITIONCORRECTION_H

#include <fun4all/SubsysReco.h>

#include <phparameter/PHParameters.h>

#include <string>
#include <vector>

#include <TNtuple.h>
#include <TFile.h>
#include <TH2F.h>

class PHCompositeNode;
class RawClusterContainer;

class RawClusterPositionCorrection : public SubsysReco
{
 public:
  explicit RawClusterPositionCorrection(const std::string &name);

  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;
  int End(PHCompositeNode *topNode) override;

  void CreateNodeTree(PHCompositeNode *topNode);

  void set_UseTowerInfo(const int useMode)
  {  // 0 only old tower, 1 only new (TowerInfo based),
    m_UseTowerInfo = useMode;
  }

 private:
  RawClusterContainer *_recalib_clusters{};

  std::string _det_name;

  // key: phibin, etabin
  std::vector<std::vector<float>> calib_constants_north;
  std::vector<std::vector<float>> calib_constants_south;

  int m_UseTowerInfo = 0;  // 0 only old tower, 1 only new (TowerInfo based),

  int nTowersPhi;
  int nTowersEta;
  int bins_eta;
  int bins_phi;
  std::string calib_file_north;
  std::string calib_file_south;
  int iEvent;

  TH2F* h2NorthSector;
  TH2F* h2SouthSector;
};

#endif
