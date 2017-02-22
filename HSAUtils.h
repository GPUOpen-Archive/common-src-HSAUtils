//==============================================================================
// Copyright (c) 2015-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  Some helper functions for using HSA
//==============================================================================

#ifndef _HSA_UTILS_H
#define _HSA_UTILS_H

#include <vector>

#include "HSAModule.h"
#include "TSingleton.h"

typedef std::vector<uint32_t> HSADeviceIdList; ///< typedef for a list of hsa devices

/// Singleton HSA Utilities class
class HSAUtils : public TSingleton<HSAUtils>
{
    friend class TSingleton<HSAUtils>;

public:
    /// constructor
    HSAUtils();

    // destructor
    ~HSAUtils();

    /// Gets a list of device IDs for all GPU devices on the system
    /// \param hsaDeviceIds the list of device IDs on the systems
    /// \return true if the list of device ids was populated sucessfully; false otherwise
    bool GetHSADeviceIds(HSADeviceIdList& hsaDeviceIds);

private:
    /// Inits the HSA Module
    /// \returns true on success
    bool InitHSAModule();

    /// Callback function for hsa_iterate_agents
    /// \param agent the hsa agent
    /// \param pData the user-defined data
    /// \return the hsa status
    static hsa_status_t GetGPUDevicesCallback(hsa_agent_t agent, void* pData);

    HSAModule* m_pHsaModule; ///< the hsa module
};

#endif // _HSA_UTILS_H
