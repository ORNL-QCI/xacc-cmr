#ifndef EMBEDDING_CMREMBEDDING_HPP_
#define EMBEDDING_CMREMBEDDING_HPP_

#include "EmbeddingAlgorithm.hpp"

namespace xacc {
namespace cmr {


class CMREmbedding : public xacc::quantum::EmbeddingAlgorithm {
public:

	virtual xacc::quantum::Embedding embed(std::shared_ptr<xacc::quantum::DWGraph> problem,
			std::shared_ptr<xacc::AcceleratorGraph> hardware,
			std::map<std::string, std::string> params = std::map<std::string,
					std::string>());

	virtual const std::string name() const {
		return "cmr";
	}

	virtual const std::string description() const {
		return "An EmbeddingAlgorithm wrapping the D-Wave MinorMiner.";
	}

};

}
}

#endif
