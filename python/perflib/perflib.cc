#include <Python.h>

#include "libperf.hh"

extern "C" {

    typedef struct {
        PyObject_HEAD

        libperf::PerfCounter counter;

    } PerfCounter;

    static PyObject*
    PerfCounter_new(PyTypeObject *type, PyObject *, PyObject *) {

        PerfCounter *self;

        self = (PerfCounter*)type->tp_alloc(type, 0);
        if(self != NULL) {
            PyErr_SetString(PyExc_ValueError, "could not initialize PerfCounter.");
            Py_RETURN_NONE;            
        }

        return (PyObject *)self;
    }

    static void
    PerfCounter_dealloc(PerfCounter* self) {

        Py_TYPE(self)->tp_free((PyObject*)self);
    }
    
    static int
    PerfCounter_init(PerfCounter *, PyObject *, PyObject *) {

        return 0;
    }


    static PyMethodDef PerfCounter_methods[] = {
        // {"label_frame", (PyCFunction)YOLO_label_frame, METH_VARARGS,
        //       "Returns labels for objects in the frame by pushing the frame through the YOLO CNN."
        // },
        {NULL, NULL, METH_VARARGS, ""}  /* Sentinel */
    };
    
    static PyTypeObject PerfCounterType = {
        PyObject_HEAD_INIT(NULL)
        .tp_name = "perflib.PerfCounter",
        .tp_basicsize = sizeof(PerfCounter),
        .tp_itemsize = 0,
        .tp_dealloc = (destructor)PerfCounter_dealloc,
        .tp_print = 0,
        .tp_getattr = 0,
        .tp_setattr = 0,
        .tp_as_async = 0,
        .tp_repr = 0,
        .tp_as_number = 0,
        .tp_as_sequence = 0,
        .tp_as_mapping = 0,
        .tp_hash = 0,
        .tp_call = 0,
        .tp_str = 0,
        .tp_getattro = 0,
        .tp_setattro = 0,
        .tp_as_buffer = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_doc = "PerfCounter object",
        .tp_traverse = 0,
        .tp_clear = 0,
        .tp_richcompare = 0,
        .tp_weaklistoffset = 0,
        .tp_iter = 0,
        .tp_iternext = 0,
        .tp_methods = PerfCounter_methods,
        .tp_members = 0,
        .tp_getset = 0,
        .tp_base = 0,
        .tp_dict = 0,
        .tp_descr_get = 0,
        .tp_descr_set = 0,
        .tp_dictoffset = 0,
        .tp_init = (initproc)PerfCounter_init,
        .tp_alloc = 0,
        .tp_new = PerfCounter_new,
        .tp_free = 0,
        .tp_is_gc = 0,
        .tp_bases = 0,
        .tp_mro = 0,
        .tp_cache = 0,
        .tp_subclasses = 0,
        .tp_weaklist = 0,
        .tp_del = 0,
        .tp_version_tag = 0,
        .tp_finalize = 0,
    };

    struct module_state {
        PyObject *error;
    };

    static struct PyModuleDef module_def = {
        PyModuleDef_HEAD_INIT,
        "perflib",
        NULL,
        sizeof(struct module_state),
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    };

    PyMODINIT_FUNC
    initperflib(void)
    {

        if (PyType_Ready(&PerfCounterType) < 0){
            PyErr_SetString(PyExc_ValueError, "could not intialize PerfCounter object.");
            Py_RETURN_NONE;
        }

        PyObject* module = PyModule_Create(&module_def);

        if (module == NULL){
            PyErr_SetString(PyExc_ValueError, "could not create perlib module.");
            Py_RETURN_NONE;        
        }

        Py_INCREF(&PerfCounterType);
        PyModule_AddObject(module, "PerfCounter", (PyObject *)&PerfCounterType);

        return module;
    }

}
