#include "parts.h"
#include "util.h"


static PyObject *
complex_fromccomplex(PyObject *Py_UNUSED(module), PyObject *obj)
{
    Py_complex complex;

    if (!PyArg_Parse(obj, "D", &complex)) {
        return NULL;
    }

    return PyComplex_FromCComplex(complex);
}

static PyObject *
complex_asccomplex(PyObject *Py_UNUSED(module), PyObject *obj)
{
    Py_complex complex;

    NULLABLE(obj);
    complex = PyComplex_AsCComplex(obj);

    if (complex.real == -1. && PyErr_Occurred()) {
        return NULL;
    }

    return PyComplex_FromCComplex(complex);
}

static PyObject*
_py_c_neg(PyObject *Py_UNUSED(module), PyObject *num)
{
    Py_complex complex;

    complex = PyComplex_AsCComplex(num);
    if (complex.real == -1. && PyErr_Occurred()) {
        return NULL;
    }

    return PyComplex_FromCComplex(_Py_c_neg(complex));
}

#define _PY_C_FUNC2(suffix)                                      \
    static PyObject *                                            \
    _py_c_##suffix(PyObject *Py_UNUSED(module), PyObject *args)  \
    {                                                            \
        Py_complex a, b, res;                                    \
                                                                 \
        if (!PyArg_ParseTuple(args, "DD", &a, &b)) {             \
            return NULL;                                         \
        }                                                        \
                                                                 \
        errno = 0;                                               \
        res = _Py_c_##suffix(a, b);                              \
        return Py_BuildValue("Di", &res, errno);                 \
    };

#define _PY_CX_FUNC2(suffix, prefix)                                     \
    static PyObject *                                                    \
    _py_##prefix##_##suffix(PyObject *Py_UNUSED(module), PyObject *args) \
    {                                                                    \
        Py_complex a, res;                                               \
        double b;                                                        \
                                                                         \
        if (!PyArg_ParseTuple(args, "Dd", &a, &b)) {                     \
            return NULL;                                                 \
        }                                                                \
                                                                         \
        errno = 0;                                                       \
        res = _Py_##prefix##_##suffix(a, b);                             \
        return Py_BuildValue("Di", &res, errno);                         \
    };

#define _PY_XC_FUNC2(suffix, prefix)                                     \
    static PyObject *                                                    \
    _py_##prefix##_##suffix(PyObject *Py_UNUSED(module), PyObject *args) \
    {                                                                    \
        Py_complex b, res;                                               \
        double a;                                                        \
                                                                         \
        if (!PyArg_ParseTuple(args, "dD", &a, &b)) {                     \
            return NULL;                                                 \
        }                                                                \
                                                                         \
        errno = 0;                                                       \
        res = _Py_##prefix##_##suffix(a, b);                             \
        return Py_BuildValue("Di", &res, errno);                         \
    };

_PY_C_FUNC2(sum)
_PY_CX_FUNC2(sum, cr)
_PY_CX_FUNC2(sum, ci)
_PY_C_FUNC2(diff)
_PY_CX_FUNC2(diff, cr)
_PY_CX_FUNC2(diff, ci)
_PY_XC_FUNC2(diff, rc)
_PY_XC_FUNC2(diff, ic)
_PY_C_FUNC2(prod)
_PY_CX_FUNC2(prod, cr)
_PY_CX_FUNC2(prod, ci)
_PY_C_FUNC2(quot)
_PY_CX_FUNC2(quot, cr)
_PY_CX_FUNC2(quot, ci)
_PY_XC_FUNC2(quot, rc)
_PY_XC_FUNC2(quot, ic)
_PY_C_FUNC2(pow)

static PyObject*
_py_c_abs(PyObject *Py_UNUSED(module), PyObject* obj)
{
    Py_complex complex;
    double res;

    NULLABLE(obj);
    complex = PyComplex_AsCComplex(obj);

    if (complex.real == -1. && PyErr_Occurred()) {
        return NULL;
    }

    errno = 0;
    res = _Py_c_abs(complex);
    return Py_BuildValue("di", res, errno);
}


static PyMethodDef test_methods[] = {
    {"complex_fromccomplex", complex_fromccomplex, METH_O},
    {"complex_asccomplex", complex_asccomplex, METH_O},
    {"_py_c_sum", _py_c_sum, METH_VARARGS},
    {"_py_cr_sum", _py_cr_sum, METH_VARARGS},
    {"_py_ci_sum", _py_ci_sum, METH_VARARGS},
    {"_py_c_diff", _py_c_diff, METH_VARARGS},
    {"_py_cr_diff", _py_cr_diff, METH_VARARGS},
    {"_py_ci_diff", _py_ci_diff, METH_VARARGS},
    {"_py_rc_diff", _py_rc_diff, METH_VARARGS},
    {"_py_ic_diff", _py_ic_diff, METH_VARARGS},
    {"_py_c_neg", _py_c_neg, METH_O},
    {"_py_c_prod", _py_c_prod, METH_VARARGS},
    {"_py_cr_prod", _py_cr_prod, METH_VARARGS},
    {"_py_ci_prod", _py_ci_prod, METH_VARARGS},
    {"_py_c_quot", _py_c_quot, METH_VARARGS},
    {"_py_cr_quot", _py_cr_quot, METH_VARARGS},
    {"_py_ci_quot", _py_ci_quot, METH_VARARGS},
    {"_py_rc_quot", _py_rc_quot, METH_VARARGS},
    {"_py_ic_quot", _py_ic_quot, METH_VARARGS},
    {"_py_c_pow", _py_c_pow, METH_VARARGS},
    {"_py_c_abs", _py_c_abs, METH_O},
    {NULL},
};

int
_PyTestCapi_Init_Complex(PyObject *mod)
{
    if (PyModule_AddFunctions(mod, test_methods) < 0) {
        return -1;
    }

    return 0;
}
