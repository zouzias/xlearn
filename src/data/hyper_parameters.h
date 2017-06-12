//------------------------------------------------------------------------------
// Copyright (c) 2016 by contributors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

/*
Author: Chao Ma (mctt90@gmail.com)

This file defines the hyper-parameters used by xLearn.
*/

#ifndef XLEARN_DATA_HYPER_PARAMETER_H_
#define XLEARN_DATA_HYPER_PARAMETER_H_

#include <string>

#include "src/data/data_structure.h"

namespace xLearn {

//------------------------------------------------------------------------------
// We use a single data structure - HyperParam to handle all the
// hyper parameters used by xLearn.
//------------------------------------------------------------------------------
struct HyperParam {
//------------------------------------------------------------------------------
// Parameters for learning algorithms.
//------------------------------------------------------------------------------
  bool is_train = true;                    // Train or Predict ?
  std::string model_type = "linear";       // linear, FM, or FFM ?
  std::string loss_type = "cross_entropy"; // cross_entropy, squared, or hinge ?
  std::string regu_type = "l2";            // l1, l2, or Elastic-Net ?
//------------------------------------------------------------------------------
// Parameters for optimization method.
//------------------------------------------------------------------------------
  real_t learning_rate = 0.01;      // Control learning step.
  std::string updater_type = "sgd"; // SGD, adam, adagard, adadelta,
                                    // momentum, or rmsprop ?
  real_t decay_rate = 0.9;          // The decay factors used by updater.
  real_t second_decay_rate = 0.9;
  real_t regu_lambda = 0.01;        // lambda for regularizer.
  int num_iteration = 100;          // Iteration number.
//------------------------------------------------------------------------------
// Parameters for dataset
//------------------------------------------------------------------------------
  std::string file_format = "libsvm"; // libsvm, libffm, or CSV ?
  index_t max_feature = 0;            // The max value of feature
  index_t num_param = 0;              // The number of model parameters.
  index_t num_cache = 0;              // The number of cache parameters.
  index_t num_K = 0;                  // Only used in fm and ffm.
  index_t num_field = 0;              // Only used in ffm.
  std::string train_set_file;         // Filename of training data.
  std::string test_set_file;          // Filename of test data.
  std::string model_checkpoint_file;  // Filename for storing the model.
//------------------------------------------------------------------------------
// Parameters for validation
//------------------------------------------------------------------------------
  bool cross_validation = true;  // Using cross validation ?
  int num_folds = 5;             // Number of folds for cross validation
  bool early_stop = false;       // Using early-stop?
};

} // namespace XLEARN

#endif // XLEARN_DATA_HYPER_PARAMETER_H_
