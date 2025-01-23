function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtInf"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.fcn["rtGetInf"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rtGetInf.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rtGetInf.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rtGetInf.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rtGetInf.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rtGetNaN.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rtGetNaN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	stack: 13,
	stackTotal: 13};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "D:\\github仓库\\RflyExpCode\\code\\e0\\3.DesignExps\\Exp4_AttitudeSystemCodeGen_ert_rtw\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'Exp4_AttitudeSystemCodeGen_metrics\'});">Global Memory: 36(bytes) Maximum Stack: 20(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
