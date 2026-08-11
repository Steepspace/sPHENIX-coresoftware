#ifndef JETBACKGROUND_SUBTRACTTOWERS_H
#define JETBACKGROUND_SUBTRACTTOWERS_H

//===========================================================
/// \file SubtractTowers.h
/// \brief creates new UE-subtracted towers
/// \author Dennis V. Perepelitsa
//===========================================================

#include <fun4all/SubsysReco.h>

#include <string>

// forward declarations
class PHCompositeNode;

/// \class SubtractTowers
///
/// \brief creates new UE-subtracted towers
///
/// Using a previously determined background UE density, this module
/// constructs a new set of towers by subtracting the background from
/// existing raw towers
///
class SubtractTowers : public SubsysReco
{
 public:
  SubtractTowers(const std::string &name = "SubtractTowers");
  ~SubtractTowers() override {}

  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;

  void SetFlowModulation(bool use_flow_modulation) { _use_flow_modulation = use_flow_modulation; }
  void set_towerinfo(bool use_towerinfo)
  {
    m_use_towerinfo = use_towerinfo;
  }
  void set_towerNodePrefix(const std::string &prefix)
  {
    m_inputNodePrefix = prefix;
    m_outputNodePrefix = prefix;
    return;
  }
  void set_inputNodePrefix(const std::string &prefix)
  {
    m_inputNodePrefix = prefix;
  }
  void set_outputNodePrefix(const std::string &prefix)
  {
    m_outputNodePrefix = prefix;
  }
  void set_inputTowerBackgroundNode( const std::string &nodeName )
  {
    m_towerBackgroundNode = nodeName;
  }
  void SetOutputNodeSuffix(const std::string &suffix) { m_outputNodeSuffix = suffix; }

 private:
  int CreateNode(PHCompositeNode *topNode);

  bool m_use_towerinfo{false};
  bool _use_flow_modulation{false};
  std::string m_inputNodePrefix{"TOWERINFO_CALIB"};
  std::string m_outputNodePrefix{"TOWERINFO_CALIB"};
  std::string m_towerBackgroundNode{"TowerInfoBackground_Sub2"};
  std::string m_outputNodeSuffix{"_SUB1"};
  std::string EMTowerName;
  std::string IHTowerName;
  std::string OHTowerName;
};

#endif
