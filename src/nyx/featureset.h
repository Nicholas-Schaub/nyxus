#pragma once

#include <map>

enum AvailableFeatures
{
	// Pixel intensity stats
	MEAN = 0, 
	MEDIAN,  
	MIN,  
	MAX,  
	RANGE,  
	STANDARD_DEVIATION,  
	SKEWNESS,  
	KURTOSIS,  
	MEAN_ABSOLUTE_DEVIATION,  
	ENERGY,  
	ROOT_MEAN_SQUARED,  
	ENTROPY,  
	MODE,  
	UNIFORMITY,  
	P10, P25, P75, P90, 
	INTERQUARTILE_RANGE,   
	ROBUST_MEAN_ABSOLUTE_DEVIATION,   
	WEIGHTED_CENTROID_Y,   
	WEIGHTED_CENTROID_X,  

	// Morphology:
	AREA_PIXELS_COUNT,
	CENTROID_X,  
	CENTROID_Y,  
	BBOX_YMIN,  
	BBOX_XMIN,  
	BBOX_HEIGHT,  
	BBOX_WIDTH,  

	// --ellipticity related
	MAJOR_AXIS_LENGTH,
	MINOR_AXIS_LENGTH,
	ECCENTRICITY,
	ORIENTATION,

	NUM_NEIGHBORS,  
	
	EXTENT,  
	ASPECT_RATIO,  

	CONVEX_HULL_AREA,  
	SOLIDITY,  

	// --contour related
	PERIMETER,  
	EQUIVALENT_DIAMETER,
	EDGE_MEAN_INTENSITY,
	EDGE_STDDEV_INTENSITY, 
	EDGE_MAX_INTENSITY, 
	EDGE_MIN_INTENSITY, 

	CIRCULARITY,

	EROSION_PIXELS,

	// CellProfiler features [http://cellprofiler-manual.s3.amazonaws.com/CellProfiler-3.0.0/modules/measurement.html]
	CELLPROFILER_INTENSITY_INTEGRATEDINTENSITYEDGE,	// Sum of the edge pixel intensities
	CELLPROFILER_INTENSITY_MAXINTENSITYEDGE,		// Maximal edge pixel intensity
	CELLPROFILER_INTENSITY_MEANINTENSITYEDGE,		// Average edge pixel intensity
	CELLPROFILER_INTENSITY_MININTENSITYEDGE,		// Minimal edge pixel intensity
	CELLPROFILER_INTENSITY_STDDEVINTENSITYEDGE,		// Standard deviation of the edge pixel intensities

	EXTREMA_P1_X, EXTREMA_P1_Y,  
	EXTREMA_P2_X, EXTREMA_P2_Y,  
	EXTREMA_P3_X, EXTREMA_P3_Y,  
	EXTREMA_P4_X, EXTREMA_P4_Y,  
	EXTREMA_P5_X, EXTREMA_P5_Y,  
	EXTREMA_P6_X, EXTREMA_P6_Y,  
	EXTREMA_P7_X, EXTREMA_P7_Y,  
	EXTREMA_P8_X, EXTREMA_P8_Y, 

	MIN_FERET_DIAMETER,  
	MAX_FERET_DIAMETER,  
	MIN_FERET_ANGLE,  
	MAX_FERET_ANGLE,  

	STAT_FERET_DIAM_MIN,  
	STAT_FERET_DIAM_MAX,  
	STAT_FERET_DIAM_MEAN,  
	STAT_FERET_DIAM_MEDIAN,  
	STAT_FERET_DIAM_STDDEV,  
	STAT_FERET_DIAM_MODE,  

	STAT_MARTIN_DIAM_MIN,  
	STAT_MARTIN_DIAM_MAX,  
	STAT_MARTIN_DIAM_MEAN,  
	STAT_MARTIN_DIAM_MEDIAN,  
	STAT_MARTIN_DIAM_STDDEV,  
	STAT_MARTIN_DIAM_MODE,  

	STAT_NASSENSTEIN_DIAM_MIN,  
	STAT_NASSENSTEIN_DIAM_MAX,  
	STAT_NASSENSTEIN_DIAM_MEAN,  
	STAT_NASSENSTEIN_DIAM_MEDIAN,  
	STAT_NASSENSTEIN_DIAM_STDDEV,  
	STAT_NASSENSTEIN_DIAM_MODE,  

	EULER_NUMBER, 

	POLYGONALITY_AVE,  
	HEXAGONALITY_AVE,  
	HEXAGONALITY_STDDEV,  

	DIAMETER_MIN_ENCLOSING_CIRCLE,  
	DIAMETER_CIRCUMSCRIBING_CIRCLE,  
	DIAMETER_INSCRIBING_CIRCLE,  
	GEODETIC_LENGTH,  
	THICKNESS,

	// GLCM:
	TEXTURE_ANGULAR2NDMOMENT,
	TEXTURE_CONTRAST,
	TEXTURE_CORRELATION,
	TEXTURE_VARIANCE,
	TEXTURE_INVERSEDIFFERENCEMOMENT,
	TEXTURE_SUMAVERAGE,
	TEXTURE_SUMVARIANCE,
	TEXTURE_SUMENTROPY,
	TEXTURE_ENTROPY,
	TEXTURE_DIFFERENCEVARIANCE,
	TEXTURE_DIFFERENCEENTROPY,
	TEXTURE_INFOMEAS1,
	TEXTURE_INFOMEAS2,

	ZERNIKE2D,
	FRAC_AT_D, 
	MEAN_FRAC, 
	RADIAL_CV, 

	// GLRLM:
	GLRLM_SRE,	// Short Run Emphasis 
	GLRLM_LRE,	// Long Run Emphasis 
	GLRLM_GLN,	// Gray Level Non-Uniformity 
	GLRLM_GLNN,	// Gray Level Non-Uniformity Normalized 
	GLRLM_RLN,	// Run Length Non-Uniformity
	GLRLM_RLNN,	// Run Length Non-Uniformity Normalized 
	GLRLM_RP,	// Run Percentage
	GLRLM_GLV,	// Gray Level Variance 
	GLRLM_RV,	// Run Variance 
	GLRLM_RE,	// Run Entropy 
	GLRLM_LGLRE,	// Low Gray Level Run Emphasis 
	GLRLM_HGLRE,	// High Gray Level Run Emphasis 
	GLRLM_SRLGLE,	// Short Run Low Gray Level Emphasis 
	GLRLM_SRHGLE,	// Short Run High Gray Level Emphasis 
	GLRLM_LRLGLE,	// Long Run Low Gray Level Emphasis 
	GLRLM_LRHGLE,	// Long Run High Gray Level Emphasis 

	// GLSZM:
	GLSZM_SAE,	// Small Area Emphasis
	GLSZM_LAE,	// Large Area Emphasis
	GLSZM_GLN,	// Gray Level Non - Uniformity
	GLSZM_GLNN,	// Gray Level Non - Uniformity Normalized
	GLSZM_SZN,	// Size - Zone Non - Uniformity
	GLSZM_SZNN,	// Size - Zone Non - Uniformity Normalized
	GLSZM_ZP,	// Zone Percentage
	GLSZM_GLV,	// Gray Level Variance
	GLSZM_ZV,	// Zone Variance
	GLSZM_ZE,	// Zone Entropy
	GLSZM_LGLZE,	// Low Gray Level Zone Emphasis
	GLSZM_HGLZE,	// High Gray Level Zone Emphasis
	GLSZM_SALGLE,	// Small Area Low Gray Level Emphasis
	GLSZM_SAHGLE,	// Small Area High Gray Level Emphasis
	GLSZM_LALGLE,	// Large Area Low Gray Level Emphasis
	GLSZM_LAHGLE,	// Large Area High Gray Level Emphasis

	// GLDM:
	GLDM_SDE,	// Small Dependence Emphasis(SDE)
	GLDM_LDE,	// Large Dependence Emphasis (LDE)
	GLDM_GLN,	// Gray Level Non-Uniformity (GLN)
	GLDM_DN,	// Dependence Non-Uniformity (DN)
	GLDM_DNN,	// Dependence Non-Uniformity Normalized (DNN)
	GLDM_GLV,	// Gray Level Variance (GLV)
	GLDM_DV,	// Dependence Variance (DV)
	GLDM_DE,	// Dependence Entropy (DE)
	GLDM_LGLE,	// Low Gray Level Emphasis (LGLE)
	GLDM_HGLE,	// High Gray Level Emphasis (HGLE)
	GLDM_SDLGLE,	// Small Dependence Low Gray Level Emphasis (SDLGLE)
	GLDM_SDHGLE,	// Small Dependence High Gray Level Emphasis (SDHGLE)
	GLDM_LDLGLE,	// Large Dependence Low Gray Level Emphasis (LDLGLE)
	GLDM_LDHGLE,	// Large Dependence High Gray Level Emphasis (LDHGLE)

	// NGTDM:
	NGTDM_COARSENESS,
	NGTDM_CONTRAST,
	NGTDM_BUSYNESS,
	NGTDM_COMPLEXITY,
	NGTDM_STRENGTH,

	// Hu's moments 1-7 
	HU_M1, 
	HU_M2, 
	HU_M3, 
	HU_M4, 
	HU_M5, 
	HU_M6, 
	HU_M7,

	GABOR, 

	_COUNT_
};

class FeatureSet
{
public:
	FeatureSet();
	void enableAll(bool newStatus=true) { for (int i = 0; i < AvailableFeatures::_COUNT_; i++) m_enabledFeatures[i] = newStatus;	}
	void disableFeatures(std::initializer_list<AvailableFeatures>& desiredFeatures)
	{
		for (auto f : desiredFeatures)
			m_enabledFeatures[f] = false;
	}
	void enableFeatures(std::initializer_list<AvailableFeatures>& desiredFeatures) {
		for (auto f : desiredFeatures)
			m_enabledFeatures[f] = true;
	}
	void enableFeature(AvailableFeatures f) {
		m_enabledFeatures[f] = true;
	}
	void enablePixelIntenStats() {
		enableAll(false);
		m_enabledFeatures[MEAN] =
		m_enabledFeatures[MEDIAN] =
		m_enabledFeatures[MIN] =
		m_enabledFeatures[MAX] =
		m_enabledFeatures[RANGE] =
		m_enabledFeatures[STANDARD_DEVIATION] =
		m_enabledFeatures[SKEWNESS] =
		m_enabledFeatures[KURTOSIS] =
		m_enabledFeatures[MEAN_ABSOLUTE_DEVIATION] =
		m_enabledFeatures[ENERGY] =
		m_enabledFeatures[ROOT_MEAN_SQUARED] =
		m_enabledFeatures[ENTROPY] =
		m_enabledFeatures[MODE] =
		m_enabledFeatures[UNIFORMITY] =
		m_enabledFeatures[P10] = m_enabledFeatures[P25] = m_enabledFeatures[P75] = m_enabledFeatures[P90] =
		m_enabledFeatures[INTERQUARTILE_RANGE] =
		m_enabledFeatures[ROBUST_MEAN_ABSOLUTE_DEVIATION] =
		m_enabledFeatures[WEIGHTED_CENTROID_Y] =
		m_enabledFeatures[WEIGHTED_CENTROID_X] = true;
	}
	void enableBoundingBox() {
		enableAll(false);
		m_enabledFeatures[BBOX_YMIN] = 
		m_enabledFeatures[BBOX_XMIN] = 
		m_enabledFeatures[BBOX_HEIGHT] = 
		m_enabledFeatures[BBOX_WIDTH] = true;
	}
	void enableFeret() {
		enableAll(false);
		m_enabledFeatures[MIN_FERET_DIAMETER] =
		m_enabledFeatures[MAX_FERET_DIAMETER] =
		m_enabledFeatures[MIN_FERET_ANGLE] =
		m_enabledFeatures[MAX_FERET_ANGLE] =
		m_enabledFeatures[STAT_FERET_DIAM_MIN] =
		m_enabledFeatures[STAT_FERET_DIAM_MAX] =
		m_enabledFeatures[STAT_FERET_DIAM_MEAN] =
		m_enabledFeatures[STAT_FERET_DIAM_MEDIAN] =
		m_enabledFeatures[STAT_FERET_DIAM_STDDEV] =
		m_enabledFeatures[STAT_FERET_DIAM_MODE] = true;
	}
	bool isEnabled (int fc) { return fc < AvailableFeatures::_COUNT_ ? m_enabledFeatures[fc] : false; }
	bool anyEnabled (std::initializer_list<int> F)
	{
		for (auto f : F)
			if (m_enabledFeatures[f])
				return true;
		return false;
	}
	int numOfEnabled() { 
		int cnt = 0; 
		for (int i = 0; i < AvailableFeatures::_COUNT_; i++) 
			if (m_enabledFeatures[i]) 
				cnt++; 
		return cnt;  
	}
	bool findFeatureByString (const std::string& featureName, AvailableFeatures& f);
	void show_help();

	// Relying on RVO rather than std::move
	std::vector<std::tuple<std::string, AvailableFeatures>> getEnabledFeatures();

protected:
	bool m_enabledFeatures [AvailableFeatures::_COUNT_];
	std::map<AvailableFeatures, std::string> m_featureNames; // initialized in constructor from featureset.cpp/UserFacingFeatureNames
};

extern FeatureSet theFeatureSet;