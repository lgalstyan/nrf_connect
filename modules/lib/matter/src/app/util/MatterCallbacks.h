/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#pragma once

#include <access/SubjectDescriptor.h>
#include <app/ConcreteAttributePath.h>
#include <app/ConcreteCommandPath.h>

void MatterPreAttributeReadCallback(const chip::app::ConcreteAttributePath & attributePath);
void MatterPostAttributeReadCallback(const chip::app::ConcreteAttributePath & attributePath);
void MatterPreAttributeWriteCallback(const chip::app::ConcreteAttributePath & attributePath);
void MatterPostAttributeWriteCallback(const chip::app::ConcreteAttributePath & attributePath);

/** @brief Matter Pre Command Received
 *
 * This callback is called once the message has been determined to be a command, and
 * before the command is dispatched to the receiver.
 */
CHIP_ERROR MatterPreCommandReceivedCallback(const chip::app::ConcreteCommandPath & commandPath,
                                            const chip::Access::SubjectDescriptor & subjectDescriptor);

/** @brief Matter Post Command Received
 *
 * This callback is called once the message has been determined to be a command, but
 * after it being dispatched to the receiver.
 */
void MatterPostCommandReceivedCallback(const chip::app::ConcreteCommandPath & commandPath,
                                       const chip::Access::SubjectDescriptor & subjectDescriptor);
