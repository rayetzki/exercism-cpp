#include "protein_translation.h"
#include <vector>
#include <string>

namespace protein_translation {
    std::vector<std::string> proteins(std::string rna) {
        std::vector<std::string> amino_acids{};
        amino_acids.reserve(rna.size() / 3);
        
        for (uint32_t i = 0; i < rna.size(); i += 3) {
            std::string const codon = rna.substr(i, 3);

            if (codon == "AUG") {
                amino_acids.push_back("Methionine");
            } else if (codon == "UUU" || codon == "UUC") {
                amino_acids.push_back("Phenylalanine");
            } else if (codon == "UUA" || codon == "UUG") {
                amino_acids.push_back("Leucine");
            } else if (codon == "UCU" || codon == "UCC" || codon == "UCA" || codon == "UCG") {
                amino_acids.push_back("Serine");
            } else if (codon == "UAU" || codon == "UAC") {
                amino_acids.push_back("Tyrosine");
            } else if (codon == "UGU" || codon == "UGC") {
                amino_acids.push_back("Cysteine");
            } else if (codon == "UGG") {
                amino_acids.push_back("Tryptophan");
            } else {
                break;
            }
        }

        return amino_acids;
    };
}  // namespace protein_translation
