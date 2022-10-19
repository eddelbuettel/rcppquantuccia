.onAttach <- function(libname, pkgName) {
    if (interactive()) {
        packageStartupMessage(paste0("Pleasr consider using CRAN package 'qlcal' as an actively maintained light-weight\n",
                                     "QuantLib-calendaring package. 'RcppQuantuccia' is in maintenance mode and not being\n",
                                     "extended upstream or as a CRAN package -- but 'qlcal' remains current."))
    }
}
