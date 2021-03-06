////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 ADVANCED MICRO DEVICES, INC.
//
// AMD is granting you permission to use this software and documentation(if any)
// (collectively, the "Materials") pursuant to the terms and conditions of the
// Software License Agreement included with the Materials.If you do not have a
// copy of the Software License Agreement, contact your AMD representative for a
// copy.
//
// You agree that you will not reverse engineer or decompile the Materials, in
// whole or in part, except as allowed by applicable law.
//
// WARRANTY DISCLAIMER : THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND.AMD DISCLAIMS ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY,
// INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE, NON - INFRINGEMENT, THAT THE
// SOFTWARE WILL RUN UNINTERRUPTED OR ERROR - FREE OR WARRANTIES ARISING FROM
// CUSTOM OF TRADE OR COURSE OF USAGE.THE ENTIRE RISK ASSOCIATED WITH THE USE OF
// THE SOFTWARE IS ASSUMED BY YOU.Some jurisdictions do not allow the exclusion
// of implied warranties, so the above exclusion may not apply to You.
//
// LIMITATION OF LIABILITY AND INDEMNIFICATION : AMD AND ITS LICENSORS WILL NOT,
// UNDER ANY CIRCUMSTANCES BE LIABLE TO YOU FOR ANY PUNITIVE, DIRECT,
// INCIDENTAL, INDIRECT, SPECIAL OR CONSEQUENTIAL DAMAGES ARISING FROM USE OF
// THE SOFTWARE OR THIS AGREEMENT EVEN IF AMD AND ITS LICENSORS HAVE BEEN
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.In no event shall AMD's total
// liability to You for all damages, losses, and causes of action (whether in
// contract, tort (including negligence) or otherwise) exceed the amount of $100
// USD.  You agree to defend, indemnify and hold harmless AMD and its licensors,
// and any of their directors, officers, employees, affiliates or agents from
// and against any and all loss, damage, liability and other expenses (including
// reasonable attorneys' fees), resulting from Your use of the Software or
// violation of the terms and conditions of this Agreement.
//
// U.S.GOVERNMENT RESTRICTED RIGHTS : The Materials are provided with
// "RESTRICTED RIGHTS." Use, duplication, or disclosure by the Government is
// subject to the restrictions as set forth in FAR 52.227 - 14 and DFAR252.227 -
// 7013, et seq., or its successor.Use of the Materials by the Government
// constitutes acknowledgement of AMD's proprietary rights in them.
//
// EXPORT RESTRICTIONS: The Materials may be subject to export restrictions as
//                      stated in the Software License Agreement.
//
////////////////////////////////////////////////////////////////////////////////

#include "core/inc/hsa_ext_interface.h"

#include "core/inc/runtime.h"

#include "core/inc/runtime.h"
#include "core/inc/agent.h"
#include "core/inc/host_queue.h"
#include "core/inc/memory_region.h"
#include "core/inc/queue.h"
#include "core/inc/signal.h"
#include "core/inc/default_signal.h"
#include "core/inc/interrupt_signal.h"
#include "core/inc/amd_load_map.h"
#include "core/inc/amd_loader_context.hpp"
#include "core/runtime/isa.hpp"
using namespace amd::hsa::code;


#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

hsa_status_t
hsa_executable_finalize (hsa_executable_t executable, hsa_isa_t isa, hsa_code_object_t*);

namespace core {
// Implementations for missing / unsupported extensions
template <class T0>
static T0 hsa_ext_null() {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1>
static T0 hsa_ext_null(T1) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2>
static T0 hsa_ext_null(T1, T2) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3>
static T0 hsa_ext_null(T1, T2, T3) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4>
static T0 hsa_ext_null(T1, T2, T3, T4) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
static T0 hsa_ext_null(T1, T2, T3, T4, T5) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14, class T15>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14, T15) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14, class T15, class T16>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14, T15, T16) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14, class T15, class T16, class T17>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14, T15, T16, T17) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14, class T15, class T16, class T17, class T18>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14, T15, T16, T17, T18) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14, class T15, class T16, class T17, class T18,
          class T19>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14, T15, T16, T17, T18, T19) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
          class T7, class T8, class T9, class T10, class T11, class T12,
          class T13, class T14, class T15, class T16, class T17, class T18,
          class T19, class T20>
static T0 hsa_ext_null(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                       T14, T15, T16, T17, T18, T19, T20) {
  return HSA_STATUS_ERROR_NOT_INITIALIZED;
}

ExtensionEntryPoints::ExtensionEntryPoints() { InitTable(); }

hsa_status_t
hsa_program_add_module(hsa_ext_program_t program, hsa_ext_module_t module)
{
  hsa_executable_t *executable = (hsa_executable_t*)&program;
  amd::hsa::loader::Executable *exec = amd::hsa::loader::Executable::Object(*executable);

  BrigModuleHeader *h = (BrigModuleHeader *)module;
  exec->AddModule (h);

  return HSA_STATUS_SUCCESS;
}

hsa_status_t
hsa_program_create (hsa_machine_model_t machine_model, hsa_profile_t profile,
		    hsa_default_float_rounding_mode_t default_float_rounding_mode,
		    const char* options, hsa_ext_program_t* program)
{
  hsa_executable_t *executable = (hsa_executable_t *)program;
  return hsa_executable_create(profile, HSA_EXECUTABLE_STATE_UNFROZEN, NULL, executable);
}

hsa_status_t
hsa_executable_finalize2 (hsa_executable_t executable, hsa_isa_t isa, hsa_code_object_t
*code_object)
{
  /* Get all modules.  */
  hsa_status_t status;
  amd::hsa::loader::Executable *exec = amd::hsa::loader::Executable::Object(executable);
  std::vector<BrigModuleHeader *> *modules= exec->GetAllModules();
  unsigned modules_count = modules->size ();

  /* Get name of ISA.  */
  unsigned isa_length;
  status = HSA::hsa_isa_get_info (isa, HSA_ISA_INFO_NAME_LENGTH, 0, &isa_length);
  assert(status == HSA_STATUS_SUCCESS);

  char *isa_name = (char *) malloc (isa_length + 1);
  status = HSA::hsa_isa_get_info (isa, HSA_ISA_INFO_NAME, 0, isa_name);
  assert (status == HSA_STATUS_SUCCESS);
  isa_name[isa_length] = '\0';

  // TODO: this is hack as the format is 'AMD:AMDGPU:8:0:1'
  isa_name += 11;

  /* Call HOF compiler.  */
  char isatmp[] = "/tmp/fileXXXXXX";

  /* Create temp for output ISA file.  */
  int isa_file = mkstemp (isatmp);
  assert (isa_file);
  close (isa_file);

  std::vector<char *> brig_filenames;

  std::vector<char *> arguments;
  arguments.push_back ("hof");
  char tmp[100] = "-output=";
  strcat(tmp, isatmp);
  arguments.push_back (tmp);
  arguments.push_back ("-brig");

  for (unsigned i = 0; i < modules_count; i++)
  {
    char *brig = (char *)malloc (100);
    strcpy (brig, "/tmp/fileXXXXXX");
    int brig_file = mkstemp (brig);
    assert (brig_file);
    brig_filenames.push_back (brig);

    BrigModuleHeader *m = (BrigModuleHeader *) (*modules)[i];
    unsigned int size = m->byteCount;

    ssize_t s = write (brig_file, m, size);
    assert (s == size);

    arguments.push_back (brig);

    close (brig_file);
  }

  /* Fork and execute */
  int cpid = fork();

  if (cpid == -1) 
    fprintf (stderr, "fork failed\n");
  else if(cpid == 0)
  {
    char target[100] = "-target=";
    strcat(target, isa_name);
    arguments.push_back (target);
    arguments.push_back (NULL);

    int n = execvp ("hof", arguments.data ());
    fprintf (stderr, "Could not execute hof offline compilee: %s\n", strerror (errno));
  }
  else
  {
    int status;
    int r = waitpid (0, &status, WUNTRACED | WCONTINUED);
  }

  struct stat st;
  stat(isatmp, &st);
  unsigned size = st.st_size;

  /* Memory for content of ISA file.  */
  char *isa_content = (char *) malloc (size);

  isa_file = open (isatmp, O_RDONLY);
  int x = read (isa_file, isa_content, size);
  assert (x == size);

  status = HSA::hsa_code_object_deserialize(isa_content, size, NULL, code_object);
  assert(HSA_STATUS_SUCCESS == status);
  assert(0 != code_object->handle);

  /* Remove BRIG temp files.  */
  for (unsigned i = 0; i < brig_filenames.size (); i++)
    remove (brig_filenames[i]);

  remove (isatmp);

  free (isa_content);

  return HSA_STATUS_SUCCESS;
}


hsa_status_t hsa_program_finalize(
    hsa_ext_program_t program,
    hsa_isa_t isa,
    int32_t call_convention,
    hsa_ext_control_directives_t control_directives,
    const char *options,
    hsa_code_object_type_t code_object_type,
    hsa_code_object_t *code_object)
{
  hsa_executable_t *executable = (hsa_executable_t*)&program;
  hsa_executable_finalize2 (*executable, isa, code_object);
}

void ExtensionEntryPoints::InitTable() {
  table.hsa_ext_program_create_fn = hsa_program_create;
  table.hsa_ext_program_destroy_fn = hsa_ext_null;
  table.hsa_ext_program_add_module_fn = hsa_program_add_module;
  table.hsa_ext_program_iterate_modules_fn = hsa_ext_null;
  table.hsa_ext_program_get_info_fn = hsa_ext_null;
  table.hsa_ext_program_finalize_fn = hsa_program_finalize;
  table.hsa_ext_image_get_capability_fn = hsa_ext_null;
  table.hsa_ext_image_data_get_info_fn = hsa_ext_null;
  table.hsa_ext_image_create_fn = hsa_ext_null;
  table.hsa_ext_image_import_fn = hsa_ext_null;
  table.hsa_ext_image_export_fn = hsa_ext_null;
  table.hsa_ext_image_copy_fn = hsa_ext_null;
  table.hsa_ext_image_clear_fn = hsa_ext_null;
  table.hsa_ext_image_destroy_fn = hsa_ext_null;
  table.hsa_ext_sampler_create_fn = hsa_ext_null;
  table.hsa_ext_sampler_destroy_fn = hsa_ext_null;
  table.hsa_amd_image_get_info_max_dim_fn = hsa_ext_null;
}

void ExtensionEntryPoints::Unload() {
  for (int i = 0; i < libs_.size(); i++) {
    void* ptr = os::GetExportAddress(libs_[i], "Unload");
    if (ptr) {
      ((Unload_t)ptr)();
    }
  }
  for (int i = 0; i < libs_.size(); i++) {
    os::CloseLib(libs_[i]);
  }
  libs_.clear();
  InitTable();
}

bool ExtensionEntryPoints::Load(std::string library_name) {
  os::LibHandle lib = os::LoadLib(library_name);
  if (lib == NULL) {
    return false;
  }
  libs_.push_back(lib);

  void* ptr;

  ptr = os::GetExportAddress(lib, "hsa_ext_program_create_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_program_create_fn ==
               (decltype(::hsa_ext_program_create)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_program_create_fn = (decltype(::hsa_ext_program_create)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_program_destroy_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_program_destroy_fn ==
               (decltype(::hsa_ext_program_destroy)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_program_destroy_fn =
        (decltype(::hsa_ext_program_destroy)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_program_add_module_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_program_add_module_fn ==
               (decltype(::hsa_ext_program_add_module)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_program_add_module_fn =
        (decltype(::hsa_ext_program_add_module)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_program_iterate_modules_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_program_iterate_modules_fn ==
               (decltype(::hsa_ext_program_iterate_modules)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_program_iterate_modules_fn =
        (decltype(::hsa_ext_program_iterate_modules)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_program_get_info_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_program_get_info_fn ==
               (decltype(::hsa_ext_program_get_info)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_program_get_info_fn =
        (decltype(::hsa_ext_program_get_info)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_program_finalize_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_program_finalize_fn ==
               (decltype(::hsa_ext_program_finalize)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_program_finalize_fn =
        (decltype(::hsa_ext_program_finalize)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_get_capability_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_get_capability_fn ==
               (decltype(::hsa_ext_image_get_capability)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_get_capability_fn =
        (decltype(::hsa_ext_image_get_capability)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_data_get_info_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_data_get_info_fn ==
               (decltype(::hsa_ext_image_data_get_info)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_data_get_info_fn =
        (decltype(::hsa_ext_image_data_get_info)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_create_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_create_fn ==
               (decltype(::hsa_ext_image_create)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_create_fn = (decltype(::hsa_ext_image_create)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_import_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_import_fn ==
               (decltype(::hsa_ext_image_import)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_import_fn = (decltype(::hsa_ext_image_import)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_export_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_export_fn ==
               (decltype(::hsa_ext_image_export)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_export_fn = (decltype(::hsa_ext_image_export)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_copy_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_copy_fn ==
               (decltype(::hsa_ext_image_copy)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_copy_fn = (decltype(::hsa_ext_image_copy)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_clear_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_clear_fn ==
               (decltype(::hsa_ext_image_clear)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_clear_fn = (decltype(::hsa_ext_image_clear)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_image_destroy_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_image_destroy_fn ==
               (decltype(::hsa_ext_image_destroy)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_image_destroy_fn = (decltype(::hsa_ext_image_destroy)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_sampler_create_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_sampler_create_fn ==
               (decltype(::hsa_ext_sampler_create)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_sampler_create_fn = (decltype(::hsa_ext_sampler_create)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_ext_sampler_destroy_impl");
  if (ptr != NULL) {
    assert(table.hsa_ext_sampler_destroy_fn ==
               (decltype(::hsa_ext_sampler_destroy)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_ext_sampler_destroy_fn =
        (decltype(::hsa_ext_sampler_destroy)*)ptr;
  }

  ptr = os::GetExportAddress(lib, "hsa_amd_image_get_info_max_dim_impl");
  if (ptr != NULL) {
    assert(table.hsa_amd_image_get_info_max_dim_fn ==
               (decltype(::hsa_amd_image_get_info_max_dim)*)hsa_ext_null &&
           "Duplicate load of extension import.");
    table.hsa_amd_image_get_info_max_dim_fn =
        (decltype(::hsa_amd_image_get_info_max_dim)*)ptr;
  }

  core::hsa_internal_api_table_.extension_backup=table;
  core::hsa_internal_api_table_.table.std_exts_=&core::hsa_internal_api_table_.extension_backup;
  
  ptr = os::GetExportAddress(lib, "Load");
  if (ptr != NULL) {
    ((Load_t)ptr)(&core::hsa_internal_api_table_.table);
  }

  return true;
}
}  // namespace core

//---------------------------------------------------------------------------//
//   Exported extension stub functions
//---------------------------------------------------------------------------//

hsa_status_t hsa_ext_program_create(
    hsa_machine_model_t machine_model, hsa_profile_t profile,
    hsa_default_float_rounding_mode_t default_float_rounding_mode,
    const char* options, hsa_ext_program_t* program) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_program_create_fn(machine_model, profile,
                                 default_float_rounding_mode, options, program);
}

hsa_status_t hsa_ext_program_destroy(hsa_ext_program_t program) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_program_destroy_fn(program);
}

hsa_status_t hsa_ext_program_add_module(hsa_ext_program_t program,
                                        hsa_ext_module_t module) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_program_add_module_fn(program, module);
}

hsa_status_t hsa_ext_program_iterate_modules(
    hsa_ext_program_t program,
    hsa_status_t (*callback)(hsa_ext_program_t program, hsa_ext_module_t module,
                             void* data),
    void* data) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_program_iterate_modules_fn(program, callback, data);
}

hsa_status_t hsa_ext_program_get_info(hsa_ext_program_t program,
                                      hsa_ext_program_info_t attribute,
                                      void* value) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_program_get_info_fn(program, attribute, value);
}

hsa_status_t hsa_ext_program_finalize(
    hsa_ext_program_t program, hsa_isa_t isa, int32_t call_convention,
    hsa_ext_control_directives_t control_directives, const char* options,
    hsa_code_object_type_t code_object_type, hsa_code_object_t* code_object) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_program_finalize_fn(program, isa, call_convention,
                                   control_directives, options,
                                   code_object_type, code_object);
}

hsa_status_t hsa_ext_image_get_capability(
    hsa_agent_t agent, hsa_ext_image_geometry_t geometry,
    const hsa_ext_image_format_t* image_format, uint32_t* capability_mask) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_get_capability_fn(agent, geometry, image_format,
                                       capability_mask);
}

hsa_status_t hsa_ext_image_data_get_info(
    hsa_agent_t agent, const hsa_ext_image_descriptor_t* image_descriptor,
    hsa_access_permission_t access_permission,
    hsa_ext_image_data_info_t* image_data_info) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_data_get_info_fn(agent, image_descriptor,
                                      access_permission, image_data_info);
}

hsa_status_t hsa_ext_image_create(
    hsa_agent_t agent, const hsa_ext_image_descriptor_t* image_descriptor,
    const void* image_data, hsa_access_permission_t access_permission,
    hsa_ext_image_t* image) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_create_fn(agent, image_descriptor, image_data,
                               access_permission, image);
}

hsa_status_t hsa_ext_image_import(hsa_agent_t agent, const void* src_memory,
                                  size_t src_row_pitch, size_t src_slice_pitch,
                                  hsa_ext_image_t dst_image,
                                  const hsa_ext_image_region_t* image_region) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_import_fn(agent, src_memory, src_row_pitch,
                               src_slice_pitch, dst_image, image_region);
}

hsa_status_t hsa_ext_image_export(hsa_agent_t agent, hsa_ext_image_t src_image,
                                  void* dst_memory, size_t dst_row_pitch,
                                  size_t dst_slice_pitch,
                                  const hsa_ext_image_region_t* image_region) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_export_fn(agent, src_image, dst_memory, dst_row_pitch,
                               dst_slice_pitch, image_region);
}

hsa_status_t hsa_ext_image_copy(hsa_agent_t agent, hsa_ext_image_t src_image,
                                const hsa_dim3_t* src_offset,
                                hsa_ext_image_t dst_image,
                                const hsa_dim3_t* dst_offset,
                                const hsa_dim3_t* range) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_copy_fn(agent, src_image, src_offset, dst_image,
                             dst_offset, range);
}

hsa_status_t hsa_ext_image_clear(hsa_agent_t agent, hsa_ext_image_t image,
                                 const void* data,
                                 const hsa_ext_image_region_t* image_region) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_clear_fn(agent, image, data, image_region);
}

hsa_status_t hsa_ext_image_destroy(hsa_agent_t agent, hsa_ext_image_t image) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_image_destroy_fn(agent, image);
}

hsa_status_t hsa_ext_sampler_create(
    hsa_agent_t agent, const hsa_ext_sampler_descriptor_t* sampler_descriptor,
    hsa_ext_sampler_t* sampler) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_sampler_create_fn(agent, sampler_descriptor, sampler);
}

hsa_status_t hsa_ext_sampler_destroy(hsa_agent_t agent,
                                     hsa_ext_sampler_t sampler) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_ext_sampler_destroy_fn(agent, sampler);
}

//---------------------------------------------------------------------------//
//  Stubs for internal extension functions
//---------------------------------------------------------------------------//

hsa_status_t hsa_amd_image_get_info_max_dim(hsa_agent_t component,
                                            hsa_agent_info_t attribute,
                                            void* value) {
  return core::Runtime::runtime_singleton_->extensions_.table
      .hsa_amd_image_get_info_max_dim_fn(component, attribute, value);
}
