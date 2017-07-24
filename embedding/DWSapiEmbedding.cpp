#include "DWSapiEmbedding.hpp"
#include "dwave_sapi.h"

std::map<int, std::list<int>> DWSapiEmbedding::embed(std::shared_ptr<xacc::quantum::DWGraph> problem,
			std::shared_ptr<xacc::AcceleratorGraph> hardware,
			std::map<std::string, std::string> params) {

	std::map<int, std::list<int>> embedding;
	auto probN = problem->order();
	auto hardN = hardware->order();

	std::vector<sapi_ProblemEntry> probEntries, hardEntries;
	for (int i = 0; i < probN; i++) {
		embedding.insert(std::make_pair(i, std::list<int>{}));
		for (int j = 0; j < probN; j++) {
			if (i < j && problem->edgeExists(i, j)) {
				probEntries.push_back( { i, j, 1.0 });
			}
		}
	}

	for (int i = 0; i < hardN; i++) {
		for (int j = 0; j < hardN; j++) {
			if (i < j && hardware->edgeExists(i, j)) {
				hardEntries.push_back( { i, j, 1.0 });
			}
		}
	}

	sapi_Problem sapiProblem = {probEntries.data(), probEntries.size()};
    sapi_Problem sapiHardware {hardEntries.data(), hardEntries.size()};

    char err_msg[SAPI_ERROR_MESSAGE_MAX_SIZE];
    sapi_Embeddings *embeddings = NULL;
    sapi_FindEmbeddingParameters find_embedding_params = SAPI_FIND_EMBEDDING_DEFAULT_PARAMETERS;

    auto code = sapi_findEmbedding(&sapiProblem, &sapiHardware, &find_embedding_params, &embeddings, err_msg);

    for (int i = 0; i < embeddings->len; i++) {
    	if (embeddings->elements[i] != -1) {
    		embedding[embeddings->elements[i]].push_back(i);
    	}
    }

	return embedding;

}

xacc::quantum::RegisterEmbeddingAlgorithm<DWSapiEmbedding> DWSAPITEMP("dw-sapi");


