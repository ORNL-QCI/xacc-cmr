/*
 * DWSapiEmbedding.hpp
 *
 *  Created on: Jul 19, 2017
 *      Author: aqw
 */

#ifndef EMBEDDING_DWSAPIEMBEDDING_HPP_
#define EMBEDDING_DWSAPIEMBEDDING_HPP_


#include "EmbeddingAlgorithm.hpp"

class DWSapiEmbedding : public xacc::quantum::EmbeddingAlgorithm {
public:

	virtual std::map<int, std::list<int>> embed(std::shared_ptr<xacc::quantum::DWGraph> problem,
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


#endif /* EMBEDDING_DWSAPIEMBEDDING_HPP_ */
