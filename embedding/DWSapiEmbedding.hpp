#ifndef EMBEDDING_DWSAPIEMBEDDING_HPP_
#define EMBEDDING_DWSAPIEMBEDDING_HPP_

#include "EmbeddingAlgorithm.hpp"

namespace xacc {
namespace dwsapi {


class DWSapiEmbedding : public xacc::quantum::EmbeddingAlgorithm {
public:

	virtual xacc::quantum::Embedding embed(std::shared_ptr<xacc::quantum::DWGraph> problem,
			std::shared_ptr<xacc::AcceleratorGraph> hardware,
			std::map<std::string, std::string> params = std::map<std::string,
					std::string>());

	/**
	 * Return the name of this Embedding Algorithm
	 * @return
	 */
	virtual std::string name() {
		return "dw-sapi";
	}
};

}
}

#endif
