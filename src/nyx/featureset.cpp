#define _USE_MATH_DEFINES	// For M_PI, etc.
#include <cmath>
#include <memory>
#include <unordered_map>
#include <unordered_set> 
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include <future>
#include <array>
#include "sensemaker.h"

#ifndef __unix
#define NOMINMAX	// Prevent converting std::min(), max(), ... into macros
#include<windows.h>
#endif

std::map <std::string, AvailableFeatures> UserFacingFeatureNames =
{
	// Pixel intensity stats
	{"MEAN", MEAN},
	{"MEDIAN", MEDIAN },
	{"MIN", MIN},
	{"MAX",MAX},
	{"RANGE",RANGE},
	{"STANDARD_DEVIATION",STANDARD_DEVIATION},
	{"SKEWNESS",SKEWNESS},
	{"KURTOSIS",KURTOSIS},
	{"MEAN_ABSOLUTE_DEVIATION",MEAN_ABSOLUTE_DEVIATION},
	{"ENERGY",ENERGY},
	{"ROOT_MEAN_SQUARED",ROOT_MEAN_SQUARED},
	{"ENTROPY",ENTROPY},
	{"MODE",MODE},
	{"UNIFORMITY",UNIFORMITY},
	{"P10", P10},
	{"P25", P25},
	{"P75", P75},
	{"P90",P90},
	{"INTERQUARTILE_RANGE",INTERQUARTILE_RANGE},
	{"ROBUST_MEAN_ABSOLUTE_DEVIATION",ROBUST_MEAN_ABSOLUTE_DEVIATION},
	{"WEIGHTED_CENTROID_Y",WEIGHTED_CENTROID_Y},
	{"WEIGHTED_CENTROID_X",WEIGHTED_CENTROID_X},

	// Morphology:
	{"AREA_PIXELS_COUNT",AREA_PIXELS_COUNT},
	{"CENTROID_X",CENTROID_X},
	{"CENTROID_Y",CENTROID_Y},
	{"BBOX_YMIN",BBOX_YMIN},
	{"BBOX_XMIN",BBOX_XMIN},
	{"BBOX_HEIGHT",BBOX_HEIGHT},
	{"BBOX_WIDTH",BBOX_WIDTH},

	{"MAJOR_AXIS_LENGTH", MAJOR_AXIS_LENGTH}, // ellipticity
	{"MINOR_AXIS_LENGTH", MINOR_AXIS_LENGTH}, // ellipticity
	{"ECCENTRICITY",ECCENTRICITY}, // ellipticity
	{"ORIENTATION", ORIENTATION}, // ellipticity

	{"NUM_NEIGHBORS",NUM_NEIGHBORS},

	{"EXTENT",EXTENT},
	{"ASPECT_RATIO",ASPECT_RATIO},

	{"EQUIVALENT_DIAMETER",EQUIVALENT_DIAMETER},
	{"CONVEX_HULL_AREA",CONVEX_HULL_AREA},
	{"SOLIDITY",SOLIDITY},
	{"PERIMETER",PERIMETER},
	{"CIRCULARITY",CIRCULARITY},

	{"CELLPROFILER_INTENSITY_INTEGRATEDINTENSITYEDGE", CELLPROFILER_INTENSITY_INTEGRATEDINTENSITYEDGE},	// Sum of the edge pixel intensities
	{"CELLPROFILER_INTENSITY_MAXINTENSITYEDGE", CELLPROFILER_INTENSITY_MAXINTENSITYEDGE},		// Maximal edge pixel intensity
	{"CELLPROFILER_INTENSITY_MEANINTENSITYEDGE", CELLPROFILER_INTENSITY_MEANINTENSITYEDGE},		// Average edge pixel intensity
	{"CELLPROFILER_INTENSITY_MININTENSITYEDGE", CELLPROFILER_INTENSITY_MININTENSITYEDGE},		// Minimal edge pixel intensity
	{"CELLPROFILER_INTENSITY_STDDEVINTENSITYEDGE", CELLPROFILER_INTENSITY_STDDEVINTENSITYEDGE},		// Standard deviation of the edge pixel intensities

	{"EXTREMA_P1_X", EXTREMA_P1_X},
	{"EXTREMA_P1_Y",EXTREMA_P1_Y},
	{"EXTREMA_P2_X", EXTREMA_P2_X},
	{"EXTREMA_P2_Y",EXTREMA_P2_Y},
	{"EXTREMA_P3_X", EXTREMA_P3_X},
	{"EXTREMA_P3_Y",EXTREMA_P3_Y},
	{"EXTREMA_P4_X", EXTREMA_P4_X},
	{"EXTREMA_P4_Y",EXTREMA_P4_Y},
	{"EXTREMA_P5_X", EXTREMA_P5_X},
	{"EXTREMA_P5_Y",EXTREMA_P5_Y},
	{"EXTREMA_P6_X", EXTREMA_P6_X},
	{"EXTREMA_P6_Y",EXTREMA_P6_Y},
	{"EXTREMA_P7_X", EXTREMA_P7_X},
	{"EXTREMA_P7_Y",EXTREMA_P7_Y},
	{"EXTREMA_P8_X", EXTREMA_P8_X},
	{"EXTREMA_P8_Y",EXTREMA_P8_Y},

	{"MIN_FERET_DIAMETER",MIN_FERET_DIAMETER},
	{"MAX_FERET_DIAMETER",MAX_FERET_DIAMETER},
	{"MIN_FERET_ANGLE",MIN_FERET_ANGLE},
	{"MAX_FERET_ANGLE",MAX_FERET_ANGLE},

	{"STAT_FERET_DIAM_MIN",STAT_FERET_DIAM_MIN},
	{"STAT_FERET_DIAM_MAX",STAT_FERET_DIAM_MAX},
	{"STAT_FERET_DIAM_MEAN",STAT_FERET_DIAM_MEAN},
	{"STAT_FERET_DIAM_MEDIAN",STAT_FERET_DIAM_MEDIAN},
	{"STAT_FERET_DIAM_STDDEV",STAT_FERET_DIAM_STDDEV},
	{"STAT_FERET_DIAM_MODE",STAT_FERET_DIAM_MODE},

	{"STAT_MARTIN_DIAM_MIN",STAT_MARTIN_DIAM_MIN},
	{"STAT_MARTIN_DIAM_MAX",STAT_MARTIN_DIAM_MAX},
	{"STAT_MARTIN_DIAM_MEAN",STAT_MARTIN_DIAM_MEAN},
	{"STAT_MARTIN_DIAM_MEDIAN",STAT_MARTIN_DIAM_MEDIAN},
	{"STAT_MARTIN_DIAM_STDDEV",STAT_MARTIN_DIAM_STDDEV},
	{"STAT_MARTIN_DIAM_MODE",STAT_MARTIN_DIAM_MODE},

	{"STAT_NASSENSTEIN_DIAM_MIN",STAT_NASSENSTEIN_DIAM_MIN},
	{"STAT_NASSENSTEIN_DIAM_MAX",STAT_NASSENSTEIN_DIAM_MAX},
	{"STAT_NASSENSTEIN_DIAM_MEAN",STAT_NASSENSTEIN_DIAM_MEAN},
	{"STAT_NASSENSTEIN_DIAM_MEDIAN",STAT_NASSENSTEIN_DIAM_MEDIAN},
	{"STAT_NASSENSTEIN_DIAM_STDDEV",STAT_NASSENSTEIN_DIAM_STDDEV},
	{"STAT_NASSENSTEIN_DIAM_MODE",STAT_NASSENSTEIN_DIAM_MODE},

	{"EULER_NUMBER",EULER_NUMBER},

	{"POLYGONALITY_AVE",POLYGONALITY_AVE},
	{"HEXAGONALITY_AVE",HEXAGONALITY_AVE},
	{"HEXAGONALITY_STDDEV",HEXAGONALITY_STDDEV},

	{"DIAMETER_MIN_ENCLOSING_CIRCLE",DIAMETER_MIN_ENCLOSING_CIRCLE},
	{"DIAMETER_CIRCUMSCRIBING_CIRCLE",DIAMETER_CIRCUMSCRIBING_CIRCLE },
	{"DIAMETER_INSCRIBING_CIRCLE",DIAMETER_INSCRIBING_CIRCLE },
	{"GEODETIC_LENGTH",GEODETIC_LENGTH },
	{"THICKNESS",THICKNESS },

	// Texture:
	{"TEXTURE_ANGULAR2NDMOMENT", TEXTURE_ANGULAR2NDMOMENT },
	{"TEXTURE_CONTRAST", TEXTURE_CONTRAST },
	{"TEXTURE_CORRELATION", TEXTURE_CORRELATION },
	{"TEXTURE_VARIANCE", TEXTURE_VARIANCE },
	{"TEXTURE_INVERSEDIFFERENCEMOMENT", TEXTURE_INVERSEDIFFERENCEMOMENT },
	{"TEXTURE_SUMAVERAGE", TEXTURE_SUMAVERAGE },
	{"TEXTURE_SUMVARIANCE", TEXTURE_SUMVARIANCE },
	{"TEXTURE_SUMENTROPY", 	TEXTURE_SUMENTROPY },
	{"TEXTURE_ENTROPY", TEXTURE_ENTROPY },
	{"TEXTURE_DIFFERENCEVARIANCE", TEXTURE_DIFFERENCEVARIANCE },
	{"TEXTURE_DIFFERENCEENTROPY", TEXTURE_DIFFERENCEENTROPY },
	{"TEXTURE_INFOMEAS1", TEXTURE_INFOMEAS1 },
	{"TEXTURE_INFOMEAS2", TEXTURE_INFOMEAS2 },

	{"TEXTURE_ZERNIKE2D", TEXTURE_ZERNIKE2D},

	{"GLRLM_SRE", GLRLM_SRE },
	{"GLRLM_LRE", GLRLM_LRE },
	{"GLRLM_GLN", GLRLM_GLN},
	{"GLRLM_GLNN", GLRLM_GLNN},
	{"GLRLM_RLN", GLRLM_RLN},
	{"GLRLM_RLNN", GLRLM_RLNN},
	{"GLRLM_RP", GLRLM_RP},
	{"GLRLM_GLV", GLRLM_GLV},
	{"GLRLM_RV", GLRLM_RV},
	{"GLRLM_RE", GLRLM_RE},
	{"GLRLM_LGLRE", GLRLM_LGLRE},
	{"GLRLM_HGLRE", GLRLM_HGLRE},
	{"GLRLM_SRLGLE", GLRLM_SRLGLE},
	{"GLRLM_SRHGLE", GLRLM_SRHGLE},
	{"GLRLM_LRLGLE", GLRLM_LRLGLE},
	{"GLRLM_LRHGLE", GLRLM_LRHGLE},

	{"GLSZM_SAE", GLSZM_SAE},
	{"GLSZM_LAE", GLSZM_LAE},
	{"GLSZM_GLN", GLSZM_GLN },
	{"GLSZM_GLNN", GLSZM_GLNN },
	{"GLSZM_SZN", GLSZM_SZN },
	{"GLSZM_SZNN", GLSZM_SZNN },
	{"GLSZM_ZP", GLSZM_ZP },
	{"GLSZM_GLV", GLSZM_GLV },
	{"GLSZM_ZV", GLSZM_ZV },
	{"GLSZM_ZE", GLSZM_ZE },
	{"GLSZM_LGLZE", GLSZM_LGLZE },
	{"GLSZM_HGLZE", GLSZM_HGLZE },
	{"GLSZM_SALGLE", GLSZM_SALGLE },
	{"GLSZM_SAHGLE", GLSZM_SAHGLE },
	{"GLSZM_LALGLE", GLSZM_LALGLE},
	{"GLSZM_LAHGLE", GLSZM_LAHGLE},

	{ "GLDM_SDE", GLDM_SDE },
	{ "GLDM_LDE", GLDM_LDE },
	{ "GLDM_GLN", GLDM_GLN },
	{ "GLDM_DN", GLDM_DN },
	{ "GLDM_DNN", GLDM_DNN },
	{ "GLDM_GLV", GLDM_GLV },
	{ "GLDM_DV", GLDM_DV },
	{ "GLDM_DE", GLDM_DE },
	{ "GLDM_LGLE", GLDM_LGLE },
	{ "GLDM_HGLE", GLDM_HGLE },
	{ "GLDM_SDLGLE", GLDM_SDLGLE },
	{ "GLDM_SDHGLE", GLDM_SDHGLE },
	{ "GLDM_LDLGLE", GLDM_LDLGLE },
	{ "GLDM_LDHGLE", GLDM_LDHGLE },

	{ "NGTDM_COARSENESS", NGTDM_COARSENESS },
	{ "NGTDM_CONTRAST", NGTDM_CONTRAST },
	{ "NGTDM_BUSYNESS", NGTDM_BUSYNESS },
	{ "NGTDM_COMPLEXITY", NGTDM_COMPLEXITY },
	{ "NGTDM_STRENGTH", NGTDM_STRENGTH },

};

FeatureSet::FeatureSet()
{
	enableAll(true);
	
	// Populate the feature code-2-name map
	for (auto& f : UserFacingFeatureNames)
	{
		m_featureNames[f.second] = f.first;
	}
}

double LR::getValue (AvailableFeatures f)
{
	return fvals[f][0];
}

bool FeatureSet::findFeatureByString(const std::string& featureName, AvailableFeatures& f)
{
	if (UserFacingFeatureNames.find(featureName) == UserFacingFeatureNames.end())
		return false;

	f = UserFacingFeatureNames[featureName];
	return true;
}

void FeatureSet::show_help()
{
	std::cout << "Names of available features:\n";
	for (auto itr = UserFacingFeatureNames.begin(); itr != UserFacingFeatureNames.end(); ++itr) 
	{
		std::cout << '\t' << itr->first << '\n';
	}
}

// Relying on RVO rather than std::move
std::vector<std::tuple<std::string, AvailableFeatures>> FeatureSet::getEnabledFeatures()
{
	std::vector<std::tuple<std::string, AvailableFeatures>> F;
	for (int i = 0; i < AvailableFeatures::_COUNT_; i++)
	{
		if (m_enabledFeatures[i])
		{
			std::tuple<std::string, AvailableFeatures> f (m_featureNames[(AvailableFeatures)i], (AvailableFeatures)i);
			F.push_back(f);
		}
	}
	return F;
}

