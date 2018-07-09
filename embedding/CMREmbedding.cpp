#include "CMREmbedding.hpp"
#include "find_embedding.hpp"

namespace xacc {
namespace cmr {

xacc::quantum::Embedding CMREmbedding::embed(std::shared_ptr<xacc::quantum::DWGraph> problem,
			std::shared_ptr<xacc::AcceleratorGraph> hardware,
			std::map<std::string, std::string> params) {

	xacc::quantum::Embedding embedding;
	auto probN = problem->order();
	auto hardN = hardware->order();


	return embedding;

}

}
}
