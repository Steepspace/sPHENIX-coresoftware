#ifndef JETBASE_JETMAP_H
#define JETBASE_JETMAP_H

#include "Jet.h"

#include <phool/PHObject.h>

#include <cstddef>  // for size_t
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

class JetMap : public PHObject
{
 public:
  // jet object iterators
  typedef std::map<unsigned int, Jet*> typ_JetMap;
  typedef typ_JetMap::const_iterator ConstIter;
  typedef typ_JetMap::iterator Iter;

  typedef std::vector<Jet*> vec_JetMap;  // to be used when sorting typ_JetMap to iterate over

  // source identifier iterators
  typedef std::set<Jet::SRC>::const_iterator ConstSrcIter;
  typedef std::set<Jet::SRC>::iterator SrcIter;

  JetMap() = default;
  ~JetMap() override = default;

  void identify(std::ostream& os = std::cout) const override;
  int isValid() const override { return 0; }
  PHObject* CloneMe() const override { return nullptr; }

  // map content info ----------------------------------------------------------

  virtual void set_algo(Jet::ALGO /*algo*/) { return; }
  virtual Jet::ALGO get_algo() const { return Jet::NONE; }

  virtual void set_par(float) { return; }
  virtual float get_par() const { return std::numeric_limits<float>::quiet_NaN(); }

  // set access to list of source identifiers ----------------------------------

  virtual bool empty_src() const { return true; }
  virtual void insert_src(Jet::SRC /*src*/) { return; }

  virtual ConstSrcIter begin_src() const;
  virtual ConstSrcIter find_src(Jet::SRC src) const;
  virtual ConstSrcIter end_src() const;

  virtual SrcIter begin_src();
  virtual SrcIter find_src(Jet::SRC src);
  virtual SrcIter end_src();

  // map access to jets --------------------------------------------------------

  virtual bool empty() const { return true; }
  virtual size_t size() const { return 0; }
  virtual size_t count(unsigned int /*idkey*/) const { return 0; }
  virtual void clear() { return; }

  virtual const Jet* get(unsigned int /*idkey*/) const { return nullptr; }
  virtual Jet* get(unsigned int /*idkey*/) { return nullptr; }

  virtual Jet* insert(Jet* /*jet*/) { return nullptr; }
  virtual size_t erase(unsigned int /*idkey*/) { return 0; }

  virtual ConstIter begin() const;
  virtual ConstIter find(unsigned int idkey) const;
  virtual ConstIter end() const;

  virtual Iter begin();
  virtual Iter find(unsigned int idkey);
  virtual Iter end();

  virtual std::vector<Jet*> vec() = 0;

 private:
  ClassDefOverride(JetMap, 1);
};

#endif
